#include <gtk/gtk.h>
#include <cairo.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
GtkWidget *draw_area, *stats, *entry_alloc, *entry_free, *combo;
gboolean on_draw(GtkWidget *w, cairo_t *cr, gpointer d)
{
    cairo_set_source_rgb(cr,0.08,0.08,0.08);
    cairo_paint(cr);
    block_t *t = head;
    int x = 20;
    while(t)
    {
        if(t->free)
            cairo_set_source_rgb(cr,0.7,0.7,0.7);
        else
            cairo_set_source_rgb(cr,0.2,0.8,0.3);

        cairo_rectangle(cr,x,60,t->size,80);
        cairo_fill_preserve(cr);
        cairo_set_source_rgb(cr,0,0,0);
        cairo_stroke(cr);
        char txt[64];
        sprintf(txt,"ID:%d",t->id);
        cairo_move_to(cr,x+5,90);
        cairo_show_text(cr,txt);
        sprintf(txt,"%ld",(long)t->size);
        cairo_move_to(cr,x+5,110);
        cairo_show_text(cr,txt);
        x += t->size + 10;
        t = t->next;
    }
    return FALSE;
}
void refresh_stats()
{
    int total = total_bytes();
    int frag = total ? (free_bytes()*100/total) : 0;
    char txt[256];
    sprintf(txt,
    "Used:%d  Free:%d  Blocks:%d  Total:%d Bytes  Fragmentation:%d%%  Strategy:%s",
    count_used(), count_free(), count_total(),
    total, frag,
    strategy_mode==0 ? "First Fit" : "Best Fit");
    gtk_label_set_text(GTK_LABEL(stats), txt);
}
void allocate_now(GtkWidget *w, gpointer d)
{
    int val = atoi(gtk_entry_get_text(GTK_ENTRY(entry_alloc)));
    if(val > 0) my_malloc(val);
    gtk_widget_queue_draw(draw_area);
    refresh_stats();
}
void free_now(GtkWidget *w, gpointer d)
{
    int id = atoi(gtk_entry_get_text(GTK_ENTRY(entry_free)));
    my_free_id(id);
    gtk_widget_queue_draw(draw_area);
    refresh_stats();
}
void reset_now(GtkWidget *w, gpointer d)
{
    reset_heap();
    gtk_widget_queue_draw(draw_area);
    refresh_stats();
}
void defrag_now(GtkWidget *w, gpointer d)
{
    auto_defrag();
    gtk_widget_queue_draw(draw_area);
    refresh_stats();
}
void strategy_changed(GtkComboBoxText *box, gpointer d)
{
    int idx = gtk_combo_box_get_active(GTK_COMBO_BOX(box));
    strategy_mode = idx;
    refresh_stats();
}
void export_now(GtkWidget *w, gpointer d)
{
    FILE *fp = fopen("report.txt","w");
    if(!fp) return;
    fprintf(fp,"AI Powered Memory Allocator Report\n");
    fprintf(fp,"Used Blocks: %d\n", count_used());
    fprintf(fp,"Free Blocks: %d\n", count_free());
    fprintf(fp,"Total Blocks: %d\n", count_total());
    fprintf(fp,"Total Bytes: %d\n", total_bytes());
    fclose(fp);
}
int main(int argc,char *argv[])
{
    gtk_init(&argc,&argv);
    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(win),"AI Powered Smart Allocator");
    gtk_window_set_default_size(GTK_WINDOW(win),1200,600);
    g_signal_connect(win,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    GtkWidget *v = gtk_box_new(GTK_ORIENTATION_VERTICAL,8);
    gtk_container_add(GTK_CONTAINER(win),v);
    GtkWidget *h = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
    gtk_box_pack_start(GTK_BOX(v),h,FALSE,FALSE,5);
    entry_alloc = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_alloc),"Bytes");
    entry_free = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_free),"Free ID");
    combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo),"First Fit");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo),"Best Fit");
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo),0);
    GtkWidget *b1 = gtk_button_new_with_label("Allocate");
    GtkWidget *b2 = gtk_button_new_with_label("Free");
    GtkWidget *b3 = gtk_button_new_with_label("Reset");
    GtkWidget *b4 = gtk_button_new_with_label("Defrag");
    GtkWidget *b5 = gtk_button_new_with_label("Export");
    gtk_box_pack_start(GTK_BOX(h),entry_alloc,FALSE,FALSE,2);
    gtk_box_pack_start(GTK_BOX(h),b1,FALSE,FALSE,2);
    gtk_box_pack_start(GTK_BOX(h),entry_free,FALSE,FALSE,2);
    gtk_box_pack_start(GTK_BOX(h),b2,FALSE,FALSE,2);
    gtk_box_pack_start(GTK_BOX(h),combo,FALSE,FALSE,2);
    gtk_box_pack_start(GTK_BOX(h),b4,FALSE,FALSE,2);
    gtk_box_pack_start(GTK_BOX(h),b5,FALSE,FALSE,2);
    gtk_box_pack_start(GTK_BOX(h),b3,FALSE,FALSE,2);
    g_signal_connect(b1,"clicked",G_CALLBACK(allocate_now),NULL);
    g_signal_connect(b2,"clicked",G_CALLBACK(free_now),NULL);
    g_signal_connect(b3,"clicked",G_CALLBACK(reset_now),NULL);
    g_signal_connect(b4,"clicked",G_CALLBACK(defrag_now),NULL);
    g_signal_connect(b5,"clicked",G_CALLBACK(export_now),NULL);
    g_signal_connect(combo,"changed",G_CALLBACK(strategy_changed),NULL);
    draw_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(draw_area,1200,450);
    g_signal_connect(draw_area,"draw",G_CALLBACK(on_draw),NULL);
    gtk_box_pack_start(GTK_BOX(v),draw_area,TRUE,TRUE,5);
    stats = gtk_label_new("No Data");
    gtk_box_pack_start(GTK_BOX(v),stats,FALSE,FALSE,5);
    gtk_widget_show_all(win);
    gtk_main();
    return 0;
}

