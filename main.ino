String nome[5];//array to store 
String senha[5];
String tipo[5];
String porta[5];

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


  Serial.println("Digite: \n 1 - Para se cadastrar \n 2 - Para consultar a lista de cadastrados \n 3 - Listagem de Eventos: \n");
  // wait for user input through serial
   while(Serial.available() == 0);

   //read the input
  String selecao = Serial.readString();
  
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
    
    Serial.println("Nome do Usuario: ");
  	// wait for user input through serial
  	while(Serial.available() == 0);

  	//read the input
 	String verificacao = Serial.readString();
    Serial.print(verificacao);
    
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
      
     	Serial.println("Entre com a senha: ");
  		// wait for user input through serial
  		while(Serial.available() == 0);

  		//read the input
 		String verificacao2 = Serial.readString();
     	Serial.print(verificacao2);
      
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
}