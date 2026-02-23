.include "m328pdef.inc"

.org 0x00
rjmp MAIN

MAIN:

    ; Set PD2–PD7 as OUTPUT (for a–f)
    ldi r16, 0b11111100
    out DDRD, r16

    ; Set PB0 as OUTPUT (for g)
    ldi r16, 0b00000001
    out DDRB, r16

    ; Common Anode → LOW = ON
    ; For digit 1 → b and c ON
    ; b = PD3, c = PD4

    ; PORTD bits:
    ; PD2=a, PD3=b, PD4=c, PD5=d, PD6=e, PD7=f
    ;
    ; a=1 OFF
    ; b=0 ON
    ; c=0 ON
    ; d=1 OFF
    ; e=1 OFF
    ; f=1 OFF

    ldi r16, 0b11100100
    out PORTD, r16

    ; g OFF (PB0 = 1)
    ldi r16, 0b00000001
    out PORTB, r16

LOOP:
    rjmp LOOP

