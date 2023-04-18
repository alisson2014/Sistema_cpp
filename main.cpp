#include <iostream>
#include <string>


using namespace std;

const int DAA_quantidadeMaximaDeProdutos = 3;
int DAA_seletorMenu; // opção selecionada no menu
int DAA_controleQuantidadeCadastrados = 0; //variavel para controlar quantos produtos foram cadastrados


string DAA_nomeProduto[DAA_quantidadeMaximaDeProdutos]; // vetor de nomes de produtos
float DAA_precoProduto[DAA_quantidadeMaximaDeProdutos]; // vetor de preço de produtos
float DAA_quantidadeProdutoEstoque[DAA_quantidadeMaximaDeProdutos]; // vetor de quantidade de produtos em estoque
string DAA_unidadeMedidaProduto[DAA_quantidadeMaximaDeProdutos]; //tipos Unidade e Mililitros

void DAA_menu(); // declaração da função que apresenta o MENU
void DAA_cadastrarProdutos(); // declaração da função que cadastro os produtos
void DAA_listarProdutos(); // declaração da função que lista os produtos
void DAA_compraDeProdutos(); // declaração da função que compra os produtos
void DAA_vendaDeProdutos();  // declaração da função que vende os produtos
void DAA_editarProdutos(); // declaração da função que edita os produtos
void DAA_excluiProdutos(); // declaração da função que excluir os produtos

//---------------------------------------------------------------------------------------------------
string DAA_voltaMenu; //variável auxiliar para esperar o usuário pressionar enter para voltar ao menu

void DAA_operacaoSucesso(){ //função para informar que a operação foi realizada com sucesso
    cout<<"Operação Realizada com Sucesso\n\n";
}

void DAA_limparTela(){ //função para limpar o console
    system("clear");
}

void DAA_limpaTelaTeclando(){ //função para limpar o console assim que o usuario teclar ENTER
    cout << "pressione enter para voltar ao MENU...";
    getline(cin,DAA_voltaMenu); // getline permite ler mais de uma palavra na mesma variável
    getline(cin,DAA_voltaMenu); // 2x getline para contornar o problema de passar pela variável sem digital nada
    DAA_limparTela(); //chamando a função de limpar o console
}

//---------------------------------------------------------------------------------------------------

void DAA_compraDeProdutos(){
    int DAA_codigoProdutoComprado;
    float DAA_quantidadeProdutoComprado;
    
    cout<<"############## Compra de Produtos #################"<<endl;
    
    cout<<"Informe o codigo do Produto: ";
    cin>>DAA_codigoProdutoComprado;
    
    while(DAA_codigoProdutoComprado < 0 || DAA_codigoProdutoComprado > DAA_controleQuantidadeCadastrados){
        cout<<"Codigo inexistente, informe um codigo valido";
        cout<<"Informe o codigo do Produto: ";
        cin>>DAA_codigoProdutoComprado;
    }
    
    //Váriaveis auxiliares
    string nomeProduto = DAA_nomeProduto[DAA_codigoProdutoComprado];
    string unidadeProduto = DAA_unidadeMedidaProduto[DAA_codigoProdutoComprado];
    int quantidadeEmEstoque = DAA_quantidadeProdutoEstoque[DAA_codigoProdutoComprado];
    
    cout<<"Você já possui "<<quantidadeEmEstoque<<unidadeProduto<<" deste produto em estoque."<<endl;
    
    cout<<"Qual a quantidade que quer comprar do Produto "<<nomeProduto<<": ";
    cin>>DAA_quantidadeProdutoComprado;
    
    DAA_quantidadeProdutoEstoque[DAA_codigoProdutoComprado] += DAA_quantidadeProdutoComprado;
    
    cout<<"O produto "<<nomeProduto<<" agora tem "<<DAA_quantidadeProdutoEstoque[DAA_codigoProdutoComprado]
        <<unidadeProduto<<" em estoque\n\n";
    
    DAA_limpaTelaTeclando();
}

//---------------------------------------------------------------------------------------------------

void DAA_vendaDeProdutos(){
    int DAA_codigoProdutoVendido;
    float DAA_quantidadeProdutoVendido;
    
    cout<<"############## Venda de Produtos #################"<<endl;
    
    cout<<"Informe o código do produto: ";
    cin>>DAA_codigoProdutoVendido;
    
    while(DAA_codigoProdutoVendido < 0 || DAA_codigoProdutoVendido > DAA_controleQuantidadeCadastrados) {
        cout<<"Codigo inexistente, informe um codigo valido";
        cout<<"Informe o código do produto: ";
        cin>>DAA_codigoProdutoVendido;
    }
    
    //Váriaveis auxiliares
    string nomeProduto, unidadeProduto;
    nomeProduto = DAA_nomeProduto[DAA_codigoProdutoVendido];
    unidadeProduto = DAA_unidadeMedidaProduto[DAA_codigoProdutoVendido];
    int quantidadeEmEstoque = DAA_quantidadeProdutoEstoque[DAA_codigoProdutoVendido];
    
    cout<<"O produto "<<nomeProduto<<" tem "<<quantidadeEmEstoque<<unidadeProduto<<" em estoque"<<endl;
    
    cout<<"Qual a quantidade que quer vender do produto "<<nomeProduto<<"? ";
    cin>>DAA_quantidadeProdutoVendido;
    
    while (quantidadeEmEstoque < DAA_quantidadeProdutoVendido || DAA_quantidadeProdutoVendido < 0) {
        if (quantidadeEmEstoque < DAA_quantidadeProdutoVendido) {
            cout<<"Quantidade insuficiente ou fora do estoque."<<endl;
            cout<<"Quantidade em estoque: "<<quantidadeEmEstoque<<unidadeProduto<<endl;
            cout<<"Digite uma quantidade válida: ";
            cin>>DAA_quantidadeProdutoVendido;
        } 
        if (DAA_quantidadeProdutoVendido < 0) {
            cout<<"Número inválido!"<<endl;
            cout<<"Digite um número inteiro positivo: ";
            cin>>DAA_quantidadeProdutoVendido; 
        }
    }
    
    DAA_quantidadeProdutoEstoque[DAA_codigoProdutoVendido] -= DAA_quantidadeProdutoVendido;
        
    cout<<"O produto "<<nomeProduto<<" agora tem "<<DAA_quantidadeProdutoEstoque[DAA_codigoProdutoVendido]
    <<unidadeProduto<<" em estoque\n\n";
    DAA_limpaTelaTeclando();
}

//---------------------------------------------------------------------------------------------------

//Funções auxiliares
void DAA_editaNome(int codigo) {
    string DAA_novoNome;
    
    cout<<"Digite o novo nome: ";
    cin>>DAA_novoNome;
    
    DAA_nomeProduto[codigo] = DAA_novoNome;
    
    DAA_operacaoSucesso();
}

void DAA_editaPreco(int codigo) {
    float DAA_novoPreco;
    
    cout<<"Digite o novo preço: ";
    cin>>DAA_novoPreco;
    
    while (DAA_novoPreco < 0) {
        cout<<"Digite somente valores positivos!"<<endl;
        cout<<"Novo preço: ";
        cin>>DAA_novoPreco;
    }
    
    DAA_precoProduto[codigo] = DAA_novoPreco;
    DAA_operacaoSucesso();
}

void DAA_editaUnidade(int codigo) {
    int DAA_novaUnidade;
    
    cout<<"Digite a nova unidade: "<<endl;
    cout<<"1 - ML, 2 - UNIDADE";
    cin>>DAA_novaUnidade;
            
    do {
        if (DAA_novaUnidade == 1) {
            DAA_unidadeMedidaProduto[codigo] = "Mililitros";
        } else if (DAA_novaUnidade == 2) {
            DAA_unidadeMedidaProduto[codigo] = "Unidade";
        } else {
            cout<<"Digite 1 para ML ou 2 para Unidade";
        }
    } while(DAA_novaUnidade != 1 && DAA_novaUnidade != 2);
    
    DAA_operacaoSucesso();
}

void DAA_editarProdutos(){
    int DAA_codigoProdutoEditado;
    
    cout<<"Digite o código do produto: ";
    cin>>DAA_codigoProdutoEditado;
    
    while (DAA_codigoProdutoEditado < 0 || DAA_codigoProdutoEditado > DAA_controleQuantidadeCadastrados) {
        cout<<"Codigo inexistente, informe um codigo valido";
        cout<<"Informe o código do produto: ";
        cin>>DAA_codigoProdutoEditado;
    }
    
    //váriaveis auxiliares
    string nomeProduto, unidadeProduto;
    nomeProduto = DAA_nomeProduto[DAA_codigoProdutoEditado];
    float precoProduto = DAA_precoProduto[DAA_codigoProdutoEditado];
    unidadeProduto = DAA_unidadeMedidaProduto[DAA_codigoProdutoEditado];
    
    cout<<"Produto: "<<nomeProduto<<endl;
    cout<<"Preço: RS"<<precoProduto<<endl;
    cout<<"Tipo: "<<unidadeProduto<<endl;
    
    int DAA_menuEditar;
    
    cout<<"1 - EDITAR TUDO"<<endl;
    cout<<"2 - EDITAR NOME"<<endl;
    cout<<"3 - EDITAR PREÇO"<<endl;
    cout<<"4 - EDITAR UNIDADE DE MEDIDA"<<endl;
    cout<<"0 - VOLTAR AO MENU"<<endl;
    cout<<"Opção do menu: ";
    cin>>DAA_menuEditar;
    
    switch(DAA_menuEditar) {
        case 0:
            DAA_limpaTelaTeclando();
            break;
        case 1:
            DAA_editaNome(DAA_codigoProdutoEditado);
            DAA_editaPreco(DAA_codigoProdutoEditado);
            DAA_editaUnidade(DAA_codigoProdutoEditado);
            DAA_limpaTelaTeclando();
            break;
        case 2:
            DAA_editaNome(DAA_codigoProdutoEditado);
            DAA_limpaTelaTeclando();
            break;
        case 3:
            DAA_editaPreco(DAA_codigoProdutoEditado);
            DAA_limpaTelaTeclando();
            break;
        case 4:
            DAA_editaUnidade(DAA_codigoProdutoEditado);
            DAA_limpaTelaTeclando();
            break;
        default:
            system("clear");
            cout << "Opção inválida" << endl;
    }
}

//---------------------------------------------------------------------------------------------------

void DAA_excluiProdutos(){
    int DAA_codigoProdutoEditado;
    
    cout<<"Digite o código do produto: ";
    cin>>DAA_codigoProdutoEditado;
    
    while (DAA_codigoProdutoEditado < 0 || DAA_codigoProdutoEditado > DAA_controleQuantidadeCadastrados) {
        cout<<"Codigo inexistente, informe um codigo valido";
        cout<<"Informe o código do produto: ";
        cin>>DAA_codigoProdutoEditado;
    }
    
    DAA_nomeProduto[DAA_codigoProdutoEditado] = "";
    DAA_precoProduto[DAA_codigoProdutoEditado] = 0;

    DAA_controleQuantidadeCadastrados--;
    cout<<DAA_nomeProduto[DAA_codigoProdutoEditado];
    DAA_operacaoSucesso();
}

//---------------------------------------------------------------------------------------------------

void DAA_cadastrarProdutos(){
    bool continuarCadastrando = true;
    while(continuarCadastrando == true){
        cout<<"############## Cadastro de Produto #################\n";
        
        if (DAA_controleQuantidadeCadastrados < DAA_quantidadeMaximaDeProdutos){ //verifica se não chegou no nivel maximo de cadastros
            cout << "Nome do produto: ";
            getline(cin,DAA_nomeProduto[DAA_controleQuantidadeCadastrados]);
            getline(cin,DAA_nomeProduto[DAA_controleQuantidadeCadastrados]);
            DAA_quantidadeProdutoEstoque[DAA_controleQuantidadeCadastrados] = 0;
            cout << "Preço do produto "<<DAA_nomeProduto[DAA_controleQuantidadeCadastrados]<<": ";
            cin >> DAA_precoProduto[DAA_controleQuantidadeCadastrados];
            int DAA_auxiliarEscolhaUnidadeMedida=0;
            do{
                cout<<"Qual a unidade de Medida do Produto?\n";
                cout<<"1 - ML ou 2 - Unidade\n";
                cin>>   DAA_auxiliarEscolhaUnidadeMedida;
                     if(DAA_auxiliarEscolhaUnidadeMedida == 1) DAA_unidadeMedidaProduto[DAA_controleQuantidadeCadastrados] = " Mililitros";
                else if(DAA_auxiliarEscolhaUnidadeMedida == 2) DAA_unidadeMedidaProduto[DAA_controleQuantidadeCadastrados] = " Unidades";
                else cout<<"Somente deve ser inserido valores 1 e 2, sendo 1 - ML ou 2 - Unidade\n";
            }while(DAA_auxiliarEscolhaUnidadeMedida < 1 || DAA_auxiliarEscolhaUnidadeMedida > 2);
        
            DAA_controleQuantidadeCadastrados++;
            DAA_operacaoSucesso();
        }else{
            cout << "Quantidade máxima de produtos atingida";
        }

        string simOuNao = "s";
        do{
            cout<<"Deseja Continuar Cadastrando?\n";
            cout<<"s = SIM ou n = Não\n";
            cin>>simOuNao;
            if(simOuNao != "s" && simOuNao != "n" && simOuNao != "S" && simOuNao != "N"){
                cout<<"Responda somente com s ou n\n";
            }else if(simOuNao == "n" || simOuNao == "N") continuarCadastrando = false;
             else{
                DAA_limparTela();   
            }
        }while(simOuNao != "s" && simOuNao != "n" && simOuNao != "S" && simOuNao != "N");
        
    }
    
    DAA_limpaTelaTeclando();
    
}

//---------------------------------------------------------------------------------------------------

void DAA_listarProdutos(){
    cout << "################ Lista de Produtos ################"<< endl;
    for (int i=0; i < DAA_controleQuantidadeCadastrados; i++) {
        cout<< DAA_quantidadeProdutoEstoque[i] << DAA_unidadeMedidaProduto[i] << " do Produto " <<
        DAA_nomeProduto[i] << "\nCom o Valor de " << DAA_precoProduto[i] << "RS em estoque, ";
        cout<<"Codigo: "<<i<<endl;
        cout<<"-------------------------------------------------------------------------\n\n";
    }
    DAA_limpaTelaTeclando();
}

//---------------------------------------------------------------------------------------------------

void DAA_menu(){
    bool fechar = false;
    
    while(fechar == false){
    
        cout << "*************************************************"<< endl;
        cout << "**************** Defensivos NSLO ****************"<< endl;
        cout << "*************************************************"<< endl;
        cout << "1 - Realizar Cadastro de Produtos"                << endl;
        cout << "2 - Realizar a Alteraração de um Produto"<< endl;
        cout << "3 - Realizar a Deleção de um Produto"             << endl;
        cout << "4 - Realizar a Compra de um Produto"              << endl;
        cout << "5 - Realizar a Venda de um Produto"               << endl;
        cout << "6 - Lista Todos os Produtos"                      << endl;
        cout << "0 - Sair do Sistema"                              << endl;
        cout << "Opção do Menu: ";
        cin >> DAA_seletorMenu;
        switch(DAA_seletorMenu) {
            case 0:
                fechar = true;
                break;
            case 1:
                DAA_limparTela();
                DAA_cadastrarProdutos();
                break;
            case 2:
                DAA_limparTela();
                DAA_editarProdutos();
                break;
            case 3:
                DAA_limparTela();
                DAA_excluiProdutos();
                break;
            case 4:
                DAA_limparTela();
                DAA_compraDeProdutos();
                break;
            case 5:
                DAA_limparTela();
                DAA_vendaDeProdutos();
                break;
            case 6:
                DAA_listarProdutos();
                DAA_listarProdutos();
                break;
            default:
                system("clear");
                cout << "Opção inválida" << endl;
        }
    }

}

int main()
{
    DAA_menu();
    return 0;
}