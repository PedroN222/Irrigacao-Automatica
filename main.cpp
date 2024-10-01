// Definição dos pinos
const int sensorDeUmidade = 7;  // Pino digital conectado ao sensor de umidade
const int releDaBomba = 8;      // Pino digital conectado ao relé da bomba de água

void setup() {
  // Configuração do pino do sensor de umidade como entrada
  pinMode(sensorDeUmidade, INPUT);

  // Configuração do pino do relé como saída
  pinMode(releDaBomba, OUTPUT);

  // Inicia o relé desligado
  digitalWrite(releDaBomba, HIGH); // Assumindo que o relé é acionado com nível LOW
}

void loop() {
  // Leitura do estado do sensor de umidade (0 ou 1)
  int estadoDeUmidade = digitalRead(sensorDeUmidade);

  // Verifica se o solo está seco (assumindo que o sensor retorna HIGH quando seco)
  if (estadoDeUmidade == HIGH) {
    // Aciona a bomba de água
    digitalWrite(releBomba, LOW); // Ativa o relé, ligando a bomba
    delay(120000); // 1 minuto com a bomba ligada para aguar todo o solo
  } else {
    // Desliga a bomba de água quando o solo estiver úmido
    digitalWrite(releBomba, HIGH); // Desativa o relé, desligando a bomba
  }

  // Pequena pausa para evitar leituras muito rápidas
  delay(1000); // 1 segundo de intervalo
}
