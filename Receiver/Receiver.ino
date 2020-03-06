#include <SoftwareSerial.h>

int randNumber;
int randDelete;
int seedForRandom = 42;
int a[20];
int b[10];
int originalArraySize = 20;
int sizeAfterDeduct = 10;
int finalSize = 5;

void setup() {
  
    Serial.begin(115200);
    //delay(2000);
    Serial1.begin(9600);
    pinMode(13,OUTPUT);
    digitalWrite(13, HIGH); 
    randomSeed(seedForRandom);
    assignArray(originalArraySize);
    
}

void loop() {
  
    if (Serial1.available() > 0)//Get the number of bytes (characters) available for reading from the serial port. This is data that’s already arrived and stored in the serial receive buffer (which holds 64 bytes).
    {
      action(char(Serial1.read()));
      
      
    }
}

void action(char number){
  
    if(number == '1'){randomPick();}
    else if(number == '2'){randomDelete();}
}

void randomPick(){

    Serial.println("");
    Serial.println("Random Pick and shuffle!");
    int j = originalArraySize;
    for(int i = 0; i < sizeAfterDeduct; i++){                       // randomly select 10 numbers and put in array b
      randNumber = random(0, j);
      b[i] = a[randNumber];
      for(int k = randNumber; k < j; k++){
        if(k != j){
         a[k] = a[k + 1]; 
        }
      }
      j -= 1;
    }

    bubbleSort();                                                    //Sorting
    Serial.println("Random Numbers ");
    printArray('b', sizeAfterDeduct);
    for(int i = sizeAfterDeduct; i < originalArraySize; i++){       //merge
      a[i] = b[i - sizeAfterDeduct];
    }
}

void randomDelete(){                                                 //select 5 final numbers from array b
  
    Serial.println("");
    Serial.println("Delete Number!");
    Serial.println("Array before Removal");
    printArray('b', sizeAfterDeduct);
    int j = sizeAfterDeduct;
    for(int k = 0; k < finalSize; k++){
      randDelete = random(0, j);// random delete
      for(int i = randDelete; i < j; i++){
        if(randDelete != i){ b[i] = b[i + 1]; }
      }
      j -= 1;
    }
    Serial.println("Array after Removal");
    printArray('b', finalSize);
}

void bubbleSort(){
  int temp;
  for(int i = 0; i < sizeAfterDeduct; i++){
    for(int j = 0; j < sizeAfterDeduct - 1; j++){
      if(b[j + 1] < b[j]){
        temp = b[j];
        b[j] = b[j + 1];
        b[j + 1] = temp;
      }
    }
  }
}

void assignArray(int originalArraySize){                  //array a size
  for(int i = 0; i < originalArraySize; i++){
    a[i] = i + 1;
  }
}

void printArray(char arrayName, int arraySize){         // print out array
  if(arrayName == 'a'){
    //Serial.println("array a ");
    for(int counter1 = 0; counter1 < arraySize; counter1++){
      Serial.print(a[counter1]);
      Serial.print(" ");
    }
    Serial.println("");
  }
  else if(arrayName == 'b'){
    for(int counter2 = 0; counter2 < arraySize; counter2++){
      Serial.print(b[counter2]);
      Serial.print(" ");
    }
    Serial.println("");
  }
}
