# Projeto-SistemaBanco
Projeto desenvolvido para disciplina de Algoritmo e Lógica de Programação II

*Descrição do Sistema*

Um banco armazena dados de seus clientes, suas contas correntes e a movimentação de cada conta. Pensando na movimentação que os clientes fazem em suas contas foi desenvolvido um sistema para controlar depósitos e saques das contas correntes.

# *Organização do Programa*

• Os dados das contas e seus clientes devem estar armazenados em estrutura e uniões como indicado a seguir: 

-Conta: deve conter o número da conta (deve ser único e gerado pelo próprio programa), saldo, número da agência, tipo da conta e os titulares da conta (deve estar vinculado aos clientes cadastrados).

-Cliente:  deve conter nome do cliente, RG, endereço, telefone, renda, tipo de cliente e numa união o cpf ou cnpj do cliente que pode ser uma pessoa física ou jurídica. 
 Defina também um typedef para as estruturas criadas.
 
• O programa deve ter uma organização que permita a execução das funcionalidades propostas. Pode ser na forma de menu de opções.

• Os dados gerados no programa devem ser armazenados em vetores de tamanho fixo.

• As funcionalidades devem ser desenvolvidas em funções.

# *Propostas de Implementação*

*1. Inserção:*

• Novas contas;
• Novos Clientes.

*2. Impressão:*

• Imprimir dados de uma conta;

• Imprimir dados de um Cliente;

• Todos os clientes de uma agência;

• Todas as contas de um tipo de uma agência.

*3.Atualização:*

• Dados dos clientes (não é permitido mudar CPF do cliente). 

• Dados das contas	(Não é permitido mudar número da conta, agência e tipo de conta).

*4. Deposito*

• Dado um valor e uma conta e uma agência, fazer uma função que faça o deposito do valor na conta.  Quando o deposito for feito faça a impressão do número da conta, do nome do cliente e do novo saldo.

*5. Saque*

• Faça uma função que execute o saque de um determinado valor da conta corrente fornecida. Se o saque foi possível imprima todos os dados da conta e se não for possível imprima uma mensagem para o usuário.

*6. Pix*

• Dado o valor do código PIX da operação, faça uma função que efetue o pagamento ou crédito do valor fornecido.

