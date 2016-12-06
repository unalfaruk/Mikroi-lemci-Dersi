GPIO_Digital_Input(&GPIO_PORTE_AHB_DATA_BITS, _GPIO_PINMASK_0);
GPIO_Digital_Output(&GPIO_PORTA_AHB, _GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIO_PORTB_AHB, _GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIO_PORTC_AHB, _GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIO_PORTD_AHB, _GPIO_PINMASK_ALL);

// Clear ports
GPIO_PORTA_AHB_DATA = 0;
GPIO_PORTB_AHB_DATA = 0;
GPIO_PORTC_AHB_DATA = 0;
GPIO_PORTD_AHB_DATA = 0;

int sayi=15,kalan=5,bolum,sayac=3,donumnoktasi, kackere=0;
int dizi[4];


void main() {

    if (Button(&GPIO_PORTE_AHB_DATA, 0, 1, 1))
    {
       kackere++;
       donum = kackere%30;
       if(donum<15)
       {

       }

    }
  
}