String nome[5];//array to store 
String senha[5];
String tipo[5];

int i = 0; //array scan

int porta1 = 2;
int porta2= 3;



void setup() {
  // Serial Configuration:
  Serial.begin(9600);
  
  //initialize the led pins
  pinMode (porta1 , OUTPUT);
  pinMode (porta2 , OUTPUT);

}

void loop() {
  int nameNo;
  bool found = false;


  Serial.println("Digite: \n 1 - Para se cadastrar \n 2 - Para consultar a lista de cadastrados \n 3 - Listagem de Eventos: ");
  // wait for user input through serial
   while(Serial.available() == 0);

   //read the input
  String selecao = Serial.readString();
  selecao.trim();// trim to remove the return character
  
 
  if(selecao=="1"){
 
      i++;
      Serial.println("Entre com o seu nome: ");
    // wait for user input through serial
      while(Serial.available() == 0);

      //read the input
      String id = Serial.readString();

    
      nome[i] = id;
  }
  
  if(selecao=="2"){
    for(int j =0 ; j<5 ; j++){

        Serial.print("" +nome[j]);
      	Serial.println("" +tipo[j]);
      }
    
  }
  if(selecao=="3"){
    
  }
  

  
}