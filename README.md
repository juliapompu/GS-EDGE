# Global Solution- Edge Computing 📊💻
**Projeto: Humantech: SafeOffice- Cuidado do ambinete HomeOffice**

Este repositório contém o projeto desenvolvido para a segunda Global Solution da disciplina *Edge Computing & Computer Systems* (FIAP - 2025). Trata-se de um sistema fisico montado com o ESP32, focado no monitoramento do ambiente de HomeOficce. Com o objetivo de deixar o ambiente de trabalho remoto mais sustentável, saudavel e tranquilo, tendo um *dashboard* completo para a empresa e o funcionário conseguirem ver e olhar como esta o espaço de trabalho remoto esteja mais seguro e saudavel.

---

## 🧩 Descrição do Desafio

A tecnologia tem avançado muito ultimamente e com essa evolução veio os *Home-Offices* e com isso as empresas não tem mais o controle de como deixar o ambiente tranquilo, saudavel e sustentável. Com o SafeOficce as empresas e os funcionários irão conseguir ver se o funcionário está trabalhando e como está o ambiente dele! Com um sensor ultrasonico de movimento e um sensor DHT 11(ou 22 por simuladores tipo Wokwi) poderam ter esses acessos atráves de um *dashboard* podendo ver as informações de Temperatura, Umidade, Distância e se ouve um Movimento.

---

### Funcionalidades implementadas:

- Leitura do nível de distância do funcionario com o Sensor de Distância,
- Sensor de Temperatura e Umidade com DHT 11 (ou 22 dependendo do simulador),
- Dashboard completo feito com HTML e CSS.

---

## 💡 Solução Técnica

O sistema foi **montado fisicamente** e também **simulado no Wokwi**.

### 🔗 Simulação no Wokwi

[Acesse o projeto clicando aqui](https://wokwi.com/projects/447295111037714433)

### 🖼️ Imagem da simulação no Tinkercad

> [image](https://github.com/user-attachments/assets/4e0b49ec-3575-4025-a75b-5b97c4443e70)

### 🎬 Vídeo Explicativo
> [clique aqui para acessar o vídeo](https://youtu.be/PEUIWi8D_Qc?si=_MVJ0XckySpBe1BW)


## 🔧 Componentes Utilizados

- 1 × **ESP 32**  
- 1 × **Sensor de Distância**
- 1 × **Sensor de temperatura e umidade (DHT11/22)**   
- Cabos Jumpers  
- 1 × Protoboard

---

## 🛠️ Montagem do Circuito (Resumo)

- **Sensor de Distância**: leitura feita nos pinos digitais 17 e 35;
- **Sensor de Temperatura e umidade (DHT11/22)**: leitura feita nos pinos digital 16;
- GND e 3V3 do ESP32 distribuídos nos trilhos laterais da protoboard.

---

## 💾 Execução do Projeto

1. Monte o circuito conforme o esquema elétrico;
2. Faça o upload do código na placa usando a IDE do ESP32;
3. Ajuste a distância manualmente (ou use o controle do Wokwi) para testar os diferentes comportamentos do sistema;
4. Assopre o sensor de temperatura(fisicamente) ou use os controles do wokwi para testar os diferentes comportamentos;
5. Faça o upload do código do Dashboard usando qualquer editor de código (aconselhamos o VS CODE);
6. Veja o Dashboard se comunicar com o código e ver os sinais ao vivo.

---

## 👥 Integrantes do Grupo

- **Julia Pompeu** – 561955
