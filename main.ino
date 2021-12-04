#define porta1 3
#define porta2 4
#define botao 2

String nome[5];//array to store 
String senha[5];
String tipo[5];
String porta[5];

int i = 0; //array scan

void botaoacionado();

void setup() {
  // Serial Configuration:
  Serial.begin(9600);
  
  //initialize the led pins
  pinMode (porta1 , OUTPUT);
  pinMode (porta2 , OUTPUT);
  
  //initialize push button
  pinMode (botao, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(botao), botaoacionado, FALLING);
  
  
}

void loop() {
  
  int nameNo;
  bool found = false;
  

  Serial.println("Digite: \n 1 - Para se cadastrar \n 2 - Para consultar a lista de cadastrados \n 3 - Listagem de Eventos \n 4 - Liberar a Porta 1 \n 5 - Liberar a Porta 2");
  // wait for user input through serial
   while(Serial.available() == 0);

   //read the input
  String selecao = Serial.readString();
  Serial.println("");
  
  if(selecao=="1"){
 
      Serial.print("Entre com o seu nome: ");
    // wait for user input through serial
      while(Serial.available() == 0);

      //read the input
      String id = Serial.readString();
   	  Serial.println(id);
      nome[i] = id;
    
   	  Serial.print("Defina uma senha: ");
   	  // wait for user input through serial
      while(Serial.available() == 0);
    
     //read the input
      String id2 = Serial.readString();
      Serial.println(id2);
      senha[i] = id2;
    
     while(tipo[i]!= "Padrao" && tipo[i]!="Admin"){
      
       Serial.print("Que tipo de usuario voce eh? (Padrao ou  Admin): ");
    	// wait for user input through serial
        while(Serial.available() == 0);

       //read the input
        String id3 = Serial.readString();
        Serial.println(id3);
        tipo[i] = id3;
      
    }
    
    Serial.println("");
    i++;
  }
  
  if(selecao=="2"){
    for(int j =0 ; j<5 ; j++){

        Serial.print("" +nome[j]);
      	Serial.println(" - " +tipo[j]);
      
      }
  }
  
  if(selecao=="3"){
    
    Serial.print("Nome do Usuario: ");
  	// wait for user input through serial
  	while(Serial.available() == 0);

  	//read the input
 	String verificacao = Serial.readString();
    Serial.println(verificacao);
    
    for(int k =0 ; k<5 ; k++){
      	if (verificacao == nome[k]){
        	  found = true;
         	  nameNo = k;
      }
    }
    
  	if(tipo[nameNo]=="Padrao"){
      
      	Serial.println("ESSE USUARIO NAO EH UM ADMIN");
      	Serial.println("");
      
      }
    
    else if(tipo[nameNo]=="Admin"){
      
     	Serial.print("Entre com a senha: ");
  		// wait for user input through serial
  		while(Serial.available() == 0);

  		//read the input
 		String verificacao2 = Serial.readString();
     	Serial.println(verificacao2);
      	
      
        if(senha[nameNo]!=verificacao2){
          
          Serial.println("SENHA INCORRETA");
          Serial.println("");
          
        }
      
      else if(senha[nameNo]==verificacao2){
        
        for(int j =0 ; j<5 ; j++){

        Serial.print("" +nome[j]);
      	Serial.print(" - " +senha[j]);
      	Serial.print(" - " +tipo[j]);
        Serial.println(" - " +porta[j]);
      
      	}
      } 
    }  
  }  
  
  //PORTA1
  if(selecao=="4"){
    
    Serial.print("Nome do Usuario: ");
    // wait for user input through serial
    while(Serial.available() == 0);

    //read the input
  String verificacao = Serial.readString();
    Serial.print(verificacao);
    Serial.println(" ");
    
    for(int k =0 ; k<5 ; k++){
        if (verificacao == nome[k]){
            found = true;
            nameNo = k;
      }
    }
    
    if(found){
    Serial.print("Entre com a senha: ");
    // wait for user input through serial
    while(Serial.available() == 0);

    //read the input
    String verificacao3 = Serial.readString();
    Serial.print(verificacao3);
    Serial.println("");
      
    if(senha[nameNo]!=verificacao3){
          
    Serial.println("SENHA INCORRETA");
    Serial.println("");
    }
      
    else if(senha[nameNo]==verificacao3){
     
    porta[nameNo] = "Porta1";
    Serial.println("Abrir Porta 1? 1 - SIM  ou 2 - NAO");
   // wait for user input through serial
      while(Serial.available() == 0);

      //read the input
      String verificacao4 = Serial.readString();
      Serial.println(verificacao4);
      
      if(verificacao4=="1"){
        digitalWrite(porta1 , HIGH);
        Serial.println("Porta1 Liberada");
        delay(5000);
        digitalWrite(porta1 , LOW);
      }
    }
      
    }
  }
  
  
  //PORTA2
        if(selecao=="5"){{
    
    Serial.print("Nome do Usuario: ");
    // wait for user input through serial
    while(Serial.available() == 0);

    //read the input
  String verificacao6 = Serial.readString();
  Serial.print(verificacao6);
       Serial.println("");
    
    for(int k =0 ; k<5 ; k++){
        if (verificacao6 == nome[k]){
            found = true;
            nameNo = k;
      }
    }
    
    if(found){
    Serial.print("Entre com a senha: ");
    // wait for user input through serial
    while(Serial.available() == 0);

    //read the input
    String verificacao3 = Serial.readString();
    Serial.print(verificacao3);
    Serial.println("");
      
    if(senha[nameNo]!=verificacao3){
          
    Serial.println("SENHA INCORRETA");
    Serial.println("");
    }
      
    else if(senha[nameNo]==verificacao3){
      
    porta[nameNo] = "Porta2";
    Serial.println("Abrir Porta 1? 1 - SIM  ou 2 - NAO");
   // wait for user input through serial
      while(Serial.available() == 0);

      //read the input
      String verificacao5 = Serial.readString();
      Serial.println(verificacao5);
      
      if(verificacao5=="1"){
        digitalWrite(porta2 , HIGH); 
        Serial.println("Porta2 Liberada");
        delay(5000);
        digitalWrite(porta2 , LOW);
      }
    }
      
     }
  
   }
 }
}


void botaoacionado(){
  
  //Close Doors
 
  if(digitalRead(botao)== LOW){
    digitalWrite(porta1, LOW);
    digitalWrite(porta2, LOW);
  }
}

