#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int bottone1 = 6;
const int conferma = 7;
const int bottone2 = 8;

int nFinale = 30;
int totale = 0;

bool prima = true;
int valorePrec = 10;
int giocatore = 1;
   
int v1 = 0;
int v2 = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Inizia a giocare");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scegli n finale");
  pinMode(bottone1, INPUT); //meno
  pinMode(conferma, INPUT); //conferma
  pinMode(bottone2, INPUT); //più
  digitalWrite(bottone1, HIGH);
  digitalWrite(conferma, HIGH);
  digitalWrite(bottone2, HIGH);
  setNumeroFinale();
}
void setNumeroFinale()
{
  lcd.setCursor(7, 2);
  lcd.print(nFinale);
  while (digitalRead(conferma) == HIGH )
  {
    if (digitalRead(bottone1) == LOW)
    {
      if (nFinale == 100)
      {
        lcd.setCursor(9, 2);
        lcd.print(" ");
      }
      if (nFinale > 30)
      {
        nFinale--;
      }
      lcd.setCursor(7, 2);
      lcd.print(nFinale);
      delay(200);
    }
    if (digitalRead(bottone2) == LOW)
    {
      if (nFinale < 100)
      {
        nFinale++;
      }
      lcd.setCursor(7, 2);
      lcd.print(nFinale);
      delay(200);
    }
  }
  lcd.setCursor(7, 2);
  lcd.print(nFinale);
  }
  
  void partita()
  {
    while(totale<nFinale)
    {
       lcd.clear();
       lcd.setCursor(0, 0);
       giocatore=1;
       lcd.print("Giocatore ");
       lcd.print(giocatore);
       delay(1000);
       Valore(v1,giocatore);
       lcd.clear();
       lcd.setCursor(0, 0);
       giocatore=2;
       lcd.print("Giocatore ");
       lcd.print(giocatore);
       delay(1000);
       Valore(v2,giocatore);
       lcd.clear();
    }
    }
    void controllo(int v,int giocatore)
    {
      if(totale+v==nFinale)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Il vincitore e");
        lcd.setCursor(0, 1);
        lcd.print("il giocatore ");
        lcd.print(giocatore);
        delay(2000);
        }
        if(totale+v>nFinale)
        {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Il perdente e");
        lcd.setCursor(0, 1);
        lcd.print("il giocatore ");
        lcd.print(giocatore);
        delay(2000);
          }
      }
      void Valore(int v,int giocatore)
  {
    lcd.clear();
    lcd.setCursor(9, 2);
    lcd.print("tot:");
    lcd.setCursor(2, 2);
    lcd.print("n:");
    lcd.setCursor(4, 2);
    lcd.print(v);
    lcd.setCursor(13, 2);
    lcd.print(totale);
    delay(200);
    lcd.setCursor(0, 0);
    lcd.print("Scegli un valore");
  while (digitalRead(conferma) == HIGH )
  {
    if (digitalRead(bottone1) == LOW)
    {
      if (v > 0)
      {
        v--;
      }
      lcd.setCursor(4, 2);
      lcd.print(v);
      lcd.setCursor(13, 2);
      lcd.print(totale);
      delay(200);
    }
    if (digitalRead(bottone2) == LOW)
    {
      if (v < 6)
      {
        v++;
      }
      lcd.setCursor(7, 2);
       lcd.setCursor(4, 2);
      lcd.print(v);
      lcd.setCursor(13, 2);
      lcd.print(totale);
      delay(200);
    }
  }
    if(v==valorePrec)
    {
    Valore(v,giocatore);
    return;
    }
    if(7-valorePrec==v)
    {
      Valore(v,giocatore);
      return;
    }
    if(prima==false&&v==0)
    {
      Valore(v,giocatore);
      return;
    }
      lcd.setCursor(4, 2);
      lcd.print(v);
      lcd.setCursor(13, 2);
      lcd.print(totale);
      delay(200);
  controllo(v,giocatore);
  totale += v;
  valorePrec = v;
  prima = false;
    }
void loop() {
 partita();
 lcd.clear();
 lcd.print("Inizia nuova partita");
 delay(2000);
 totale = 0;
}
