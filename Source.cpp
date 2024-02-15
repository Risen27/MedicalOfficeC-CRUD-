#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;


class consulta
{
	int id;
	int code;
	char nome[50];
	char diagnostico[10];
	char tipologia[10];
	char data[30];
	float preco;

public:
	int get_ID();
	void get_info();
	void get_nome();
	void get_code();
	void get_data();
	void get_preco();
	void get_diagnostico();
	void get_tipologia();
	int verificar_especializacao(int opt, int flag);
	void mostrar_tudo(consulta d);
	void mostrar_info(consulta d);
	void modificar_consulta(consulta d, int number, int size);

};

void add_consulta_data();
int verificar_alfabeto(char* arr, int size);
void modificar_consulta_data();
void eliminar_conteudos();
void eliminar_conteudos1();
void mostrar();
void eliminar_consulta_data();
int mostrar_consulta_data();
int numero_consulta();
long int get_size_of_the_file();

int  verificar_alfabeto(char* arr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (isdigit(arr[i]))
		{
			return(1);
		}
	}
}
int numero_consulta()
{
	long int size;
	size = get_size_of_the_file();
	consulta d;
	size = size / (sizeof(d));
	return(size);
}

int consulta::verificar_especializacao(int opt, int flag)
{
	if (opt == code)
	{
		flag++;
		cout << "\n" << "ID------------->\t" << get_ID();
		return(flag);
	}
	else
	{
		return(flag);
	}
}
int consulta::get_ID()
{
	return(id);
}
void consulta::get_info()
{
	cout << "\nEscreva o ID da consulta              :";
	cin >> id;
NOME:
	cout << "\nEscreva o nome do paciente a que pretende atribuir a consulta            :";
	cin.ignore();
	cin.getline(nome, 50);
	int flag;
	int size = strlen(nome);

DIAGNOSTICO:
	cout << "\nEscreva o diagnostico    :";
	cin.ignore();
	cin.getline(diagnostico, 50);
	size = strlen(diagnostico);
	flag = verificar_alfabeto(diagnostico, size);

TIPOLOGIA:
	cout << "\nEscreva a tipologia do diagnostico :";
	cin.getline(tipologia, 50);
	size = strlen(tipologia);
	flag = verificar_alfabeto(tipologia, size);

	cout << "********************************************************************************";
	cout << "\n\t\t\tTipologias\n";
	cout << "********************************************************************************";
	cout << "1.analises clinicas\n2.imagiologia\n3.checkup\n";
	cout << "********************************************************************************";
	cin >> code;
	cout << "********************************************************************************";
	cout << "\n Escreva a data da consulta:";
	cin >> data;
	cout << "\n Digite o valor da consulta:";
	cin >> preco;
}

void consulta::get_nome()
{
NOME:
	cin.ignore();
	cout << "\nEscreva um novo nome :";
	cin >> nome;
	int flag;
	int size = strlen(nome);
	flag = verificar_alfabeto(nome, size);


}

void consulta::get_diagnostico()
{
QUALIFICATION:
	cin.ignore();
	cout << "\nEscreva um novo diagnostico :";
	cin >> diagnostico;
	int flag;
	int size = strlen(diagnostico);
	flag = verificar_alfabeto(diagnostico, size);
}
void consulta::get_tipologia()
{
TIPOLOGIA:
	cin.ignore();
	cout << "\nEscreva uma nova especializacao :";
	cin >> tipologia;
	int flag;
	int size = strlen(tipologia);
	flag = verificar_alfabeto(tipologia, size);
	cout << "********************************************************************************";
	cout << "\nTipologia\n";
	cout << "********************************************************************************";
	cout << "1.Analises clinicas\n2.Imagiologia\n3.checkup\n";
	cout << "********************************************************************************";
	cin >> code;
}

void consulta::get_data()
{
	cin.ignore();
	cout << "\nEscreva a data da consulta :";
	cin >> data;

}

void consulta::get_preco()
{
	cin.ignore();
	cout << "\nEscreva o valor da consulta:";
	cin >> preco;
}


void consulta::mostrar_info(consulta d)
{
	cout << "\nIdentificacao da consulta            :\t " << d.id;
	cout << "\nNome do paciente para a consulta      :\t" << d.nome;
	cout << "\nDiagnostico    :\t" << d.diagnostico;
	cout << "\nData da consulta           :\t" << d.data;
	cout << "\nTipologia    :\t" << d.tipologia;
	cout << "\n Preco :\t" << d.preco;



}
void consulta::mostrar_tudo(consulta d)
{
	cout << "\t" << d.nome << d.id << "\t\t" << d.tipologia << "\t\t\t" << d.diagnostico << "\t\t\t" << d.data << d.preco << "\t\t\t" << "\n";
}
void consulta::modificar_consulta(consulta d, int number, int size)
{
	if (number == 1)
	{
		fstream myfile6("consulta8.txt", ios::in | ios::out);
		consulta d1 = d;
		d1.get_nome();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		cout << "\n";
		cout << "\n";
		system("PAUSE");
		system("CLS");
		cout << "\nModificado com sucesso\n";
		myfile6.close();
		cout << " \n";
		system("PAUSE");
	}
	else if (number == 2)
	{
		fstream myfile6("consulta8.txt", ios::in | ios::out);
		consulta d1 = d;
		d1.get_diagnostico();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		cout << "\n";
		cout << "\n";
		system("PAUSE");
		system("CLS");
		cout << "\nModificado com sucesso\n";
		myfile6.close();
		cout << " \n";
		system("PAUSE");
	}
	else if (number == 3)
	{
		fstream myfile6("consulta8.txt", ios::in | ios::out);
		consulta d1 = d;
		d1.get_tipologia();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nModificado com sucesso\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}

	else if (number == 4)
	{
		fstream myfile6("consulta8.txt", ios::in | ios::out);
		consulta d1 = d;
		d1.get_data();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nModificado com sucesso\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 5)
	{
		fstream myfile6("consulta8.txt", ios::in | ios::out);
		consulta d1 = d;
		d1.get_preco();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nModificado com sucesso\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}

}
class paciente
{
	int id;
	int doc_id;
	char nome[50];
	int preco;
public:
	int  get_ID();
	void set_doc_ID();
	void get_info();
	void get_nome();
	void relatorio1(paciente);
	void get_preco();
	void preco1(paciente);
	void atribuir_paciente_consulta(paciente p, int size);
	void mostrar_tudo(paciente p);
	void mostrar_info(paciente p);
	void modificar_info(paciente p, int number, int size);
};

void adicionar_paciente_data();
void modificar_paciente_data();
void eliminar_paciente_data();
void atribuir_paciente();
void mostrar1();
void relatorio();
void conta();
int mostrar_paciente_data();
int numero();
long int get_size_of_the_file1();
void paciente::preco1(paciente p)
{
	system("CLS");
	int total;
	cout << "********************************************************************************";
	cout << "\n\n\t\t\t\tValor das Consultas\n\n ";
	cout << "*******************************************************************************";
	cout << "\nValor total da consulta              :\t " << p.preco;
	total = p.preco;
	cout << "\nTotal                      :\t" << total << "\n";
	cout << "********************************************************************************";
}
void paciente::relatorio1(paciente p)
{
	system("CLS");
	cout << "********************************************************************************";
	cout << "\n\t\t\tRelatorio\n";
	cout << "********************************************************************************";
	cout << "\nNome                                            :" << p.nome;
	cout << "\n";
	cout << "********************************************************************************";
}
int paciente::get_ID()
{
	return(id);
}
void paciente::set_doc_ID()
{
	cout << "\nescolha:";
	cin >> doc_id;
}
void paciente::get_info()
{
	cout << "\nID                                          :";
	cin >> id;
NAME:
	cout << "\nNome                                     :";
	cin.ignore();
	cin.getline(nome, 50);
	int flag;
	int size = strlen(nome);
	flag = verificar_alfabeto(nome, size);
	if (flag == 1)
	{
		cout << "\n\nName should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto NAME;
	}

	cout << "\nvalor a pagar               :";
	cin >> preco;

}
void paciente::atribuir_paciente_consulta(paciente p, int size)
{
	long int size1 = size;
	ifstream myfile1("consulta8.txt");
	size = get_size_of_the_file();
	consulta d;
	size = size / (sizeof(d));
	cout << "********************************************************************************";
	cout << "********************************************************************************";
	cout << "\n1.Analise clinica\n2.Imagiologia\n3.Checkup\n";
	cout << "********************************************************************************";
	cout << "\n\nPlease Select Your Choice :";
	int opt, flag = 0;
	int cho;
	cin >> opt;
	myfile1.seekg(0);
	switch (opt)
	{
	case 1:
		system("CLS");
		cout << "********************************************************************************";
		cout << "\n\t\tID da consulta de checkup\n";
		cout << "********************************************************************************";
		for (int i = 0; i < size; i++)
		{
			cout << "\n";
			myfile1.read((char*)&d, sizeof(d));
			flag = d.verificar_especializacao(opt, flag);

		}
		myfile1.close();
		if (flag == 0)
		{
			system("CLS");
			cout << "********************************************************************************";
			cout << "\nNao há consultas disponiveis\n";
			cout << "********************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		else
		{
			cout << "\n";
			cout << "***********************************************************************************";
			fstream myfile6("paciente11.txt", ios::in | ios::out);
			paciente p1 = p;
			myfile6.seekp(0);
			myfile6.seekg(0);
			p1.set_doc_ID();
			myfile6.seekp(size1, ios::beg);
			myfile6.write((char*)&p1, sizeof(p1));
			system("CLS");
			cout << "\nConsulta marcada com sucesso";
			cout << "\n";
			cout << "\n*****************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		break;
	case 2:
		system("CLS");
		cout << "********************************************************************************";
		cout << "\n\t\tID das consultas de imagiologia\n";
		cout << "********************************************************************************";
		for (int i = 0; i < size; i++)
		{
			cout << "\n";
			myfile1.read((char*)&d, sizeof(d));
			flag = d.verificar_especializacao(opt, flag);
		}
		if (flag == 0)
		{
			system("CLS");
			cout << "********************************************************************************";
			cout << "\nNao ha consultas desse tipo\n";
			cout << "********************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		else
		{
			cout << "\n";
			cout << "********************************************************************************";
			fstream myfile6("paciente11.txt", ios::in | ios::out);
			paciente p1 = p;
			myfile6.seekp(0);
			myfile6.seekg(0);
			p1.set_doc_ID();
			myfile6.seekp(size1, ios::beg);
			myfile6.write((char*)&p1, sizeof(p1));
			system("CLS");
			cout << "\nconsulta marcada com sucesso";
			cout << "\n";
			cout << "\n*****************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		break;
	case 3:
		system("CLS");
		cout << "********************************************************************************";
		cout << "\n\t\tID das consultas de checkup\n";
		cout << "********************************************************************************";
		for (int i = 0; i < size; i++)
		{
			cout << "\n";
			myfile1.read((char*)&d, sizeof(d));
			flag = d.verificar_especializacao(opt, flag);
		}
		if (flag == 0)
		{
			system("CLS");
			cout << "********************************************************************************";
			cout << "\nnao ha consultas de checkup\n";
			cout << "********************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		else
		{
			cout << "\n";
			cout << "********************************************************************************";
			fstream myfile6("paciente11.txt", ios::in | ios::out);
			paciente p1 = p;
			myfile6.seekp(0);
			myfile6.seekg(0);
			p1.set_doc_ID();
			myfile6.seekp(size1, ios::beg);
			myfile6.write((char*)&p1, sizeof(p1));
			system("CLS");
			cout << "\nConsulta marcada com sucesso";
			cout << "\n";
			cout << "\n*****************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}

		break;
	case 4:
		system("CLS");
		cout << "********************************************************************************";

		cout << "********************************************************************************";
		for (int i = 0; i < size; i++)
		{
			cout << "\n";
			myfile1.read((char*)&d, sizeof(d));
			flag = d.verificar_especializacao(opt, flag);
		}
		if (flag == 0)
		{
			system("CLS");
			cout << "********************************************************************************";

			cout << "********************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		else
		{
			cout << "\n";
			cout << "********************************************************************************";
			fstream myfile6("paciente11.txt", ios::in | ios::out);
			paciente p1 = p;
			myfile6.seekp(0);
			myfile6.seekg(0);
			p1.set_doc_ID();
			myfile6.seekp(size1, ios::beg);
			myfile6.write((char*)&p1, sizeof(p1));
			system("CLS");

			cout << "\n";
			cout << "\n*****************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		break;
	default:
		cout << "\nErro!!!";
	}

}

void paciente::get_nome()
{
	cout << "\nNovo nome :";
	cin.ignore();
	cin.getline(nome, 50);
}

void paciente::get_preco()
{
	cin.ignore();
	cout << "\nNovo valor a pagar   :";
	cin >> preco;
}
void paciente::mostrar_tudo(paciente p)
{
	cout << p.id << "\t" << p.nome << p.doc_id << "\n";
}
void paciente::mostrar_info(paciente p)
{
	cout << "\nID                                   :" << p.id;
	cout << "\nNome                                   :" << p.nome;
	cout << "\nPreco                                  :" << p.preco;
	cout << "\nID da consulta    :" << p.doc_id;
}
void paciente::modificar_info(paciente p, int number, int size)
{
	if (number == 1)
	{
		fstream myfile6("paciente11.txt", ios::in | ios::out);
		paciente p1 = p;
		p1.get_nome();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nModificado com sucesso\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}

	else if (number == 2)
	{
		fstream myfile6("paciente11.txt", ios::in | ios::out);
		paciente p1 = p;
		p1.get_preco();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nModificado com sucesso\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
}

void main()
{
	int counter = 0, y = 0;

	system("CLS");
START1:
	system("CLS");
	cout << "\n\t\t\t\t1.Menu\n";
	cout << "\n\t\t\t\t2.Sair\n\n";
	int op, ch, count = 0;
	char c;
	cin >> op;
	cout << "\n\n";
	system("PAUSE");
START3:
	switch (op)
	{
	case 1:
		system("CLS");
		cout << "********************************************************************************\n";
		cout << "\t\t\t\tMenu\n\n";
		cout << "********************************************************************************\n";
		cout << "\n\n\t\t1.Consultas\n";
		cout << "\n\t\t2.Pacientes\n";
		cout << "\n\t\t3.Relatorio Pacientes\n";
		cout << "\n\t\t4.Valor a Pagar pelos Pacientes\n";
		cout << "\n\t\t5.Sair\n\n";
		cout << "********************************************************************************";
		cin >> ch;
		switch (ch)
		{
		case 1:
			system("CLS");
		START2:
			count++;
			{

				cout << "\n\n";
				system("PAUSE");
				system("CLS");
				while (1)
				{
					system("CLS");
					cout << "\n\t\t1.Adicionar Consulta\n";
					cout << "\n\t\t2.Editar Consulta\n";
					cout << "\n\t\t3.Mostrar Informação da Consulta\n";
					cout << "\n\t\t4.Eliminar informação da consulta\n";
					cout << "\n\t\t5.Número de Consultas pré-existentes\n";
					cout << "\n\t\t6.Eliminar todas as consultas\n";
					cout << "\n\t\t7.Mostrar todas as consultas\n";
					cout << "\n\t\t8.Sair\n";
					int opt;
					cin >> opt;
					int y;
					switch (opt)
					{

					case 1:
						system("CLS");
						add_consulta_data();
						break;
					case 2:

						system("CLS");
						modificar_consulta_data();

						break;
					case 3:
						system("CLS");
						y = mostrar_consulta_data();
						if (y != 1)
						{
							cout << "\nNao existe!!!\n";
							cout << "\n";
							system("PAUSE");
						}

						break;
					case 4:

						system("CLS");
						eliminar_consulta_data();
						cout << "\n";
						system("PAUSE");

						break;
					case 5:
						system("CLS");
						cout << "\nNumero de consultas existentes :" << numero_consulta();
						cout << "\n\n";
						system("PAUSE");
						break;
					case 6:
						system("CLS");
						eliminar_conteudos();
						cout << "\nTudo eliminado ";
						cout << "\n\n";
						system("PAUSE");
						break;
					case 7:
						system("CLS");
						mostrar();
						cout << "\n\n";
						system("PAUSE");
						break;
					case 8:
						system("CLS");
						goto START3;
						_getch();
					}
				}
			}

		case 2:
			system("CLS");
		START4:
			count++;

			{

				cout << "\n\n";
				system("PAUSE");
				system("CLS");
				while (1)
				{
					system("CLS");
					cout << "********************************************************************************\n";
					cout << "********************************************************************************\n";
					cout << "\n\t\t1.Adicionar paciente\n";
					cout << "\n\t\t2.Atribuir consulta a paciente\n";
					cout << "\n\t\t3.Editar paciente\n";
					cout << "\n\t\t4.Mostrar Paciente\n";
					cout << "\n\t\t5.Eliminar paciente\n";
					cout << "\n\t\t6.Numero de pacientes com consultas\n";
					cout << "\n\t\t7.Eliminar todos os pacientes\n";
					cout << "\n\t\t8.Mostrar todos os pacientes\n";
					cout << "\n\t\t9.sair\n\n";
					cout << "********************************************************************************\n";
					int opt;
					cout << "\nescolha :";
					cin >> opt;
					int y;
					switch (opt)
					{
					case 1:
						system("CLS");
						adicionar_paciente_data();
						break;
					case 2:
						system("CLS");
						atribuir_paciente();
						break;
					case 3:
						system("CLS");
						modificar_paciente_data();
						break;
					case 4:
						system("CLS");
						y = mostrar_paciente_data();
						if (y != 1)
						{
							cout << "\nnada a mostrar!!!\n";
							cout << "\n";
							system("PAUSE");
						}
						break;
					case 5:
						system("CLS");
						eliminar_paciente_data();
						cout << "\n";
						system("PAUSE");
						break;
					case 6:
						system("CLS");
						cout << "\nNumero de pacientes registados :" << numero();
						cout << "\n\n";
						system("PAUSE");
						break;
					case 7:
						system("CLS");
						eliminar_conteudos1();
						cout << "\neliminado com sucesso";
						cout << "\n\n";
						system("PAUSE");
						break;
					case 8:
						system("CLS");
						mostrar1();
						cout << "\n\n";
						system("PAUSE");
						break;
					case 9:
						system("CLS");
						goto START3;
						_getch();

					}
				}
			}


		case 3:
			system("CLS");
			cout << "\n\n";
			relatorio();
			cout << "\n\n";
			system("PAUSE");
			goto START3;
			break;
		case 4:
			system("CLS");
			conta();
			cout << "\n\n";
			system("PAUSE");
			system("CLS");
			goto START3;
			break;

		case 5:
			cout << "\n";
			cout << "\n";
			goto START1;
		default:
			cout << "\nerro ";
		}
		break;
	case 2:
		cout << "\n\n";
		exit(0);
		break;
	default:
		cout << "\nerro ";
	}
	_getch();
}
void add_consulta_data()
{
	consulta d;
	ofstream myfile("consulta8.txt", ios::in | ios::app);
	d.get_info();
	myfile.write((char*)&d, sizeof(d));
	myfile.close();
}
void mostrar()
{
	long int size = 0;
	size = get_size_of_the_file();
	int i = 0;
	consulta d;
	size = size / (sizeof(d));
	if (size == 0)
	{
		cout << "\nVazio!!!";
		cout << "\n";
	}
	else
	{
		cout << "\n";
		cout << "********************************************************************************";
		cout << "\n\t\t\tDetalhes de consultas\n";
		cout << "********************************************************************************";
		cout << "\t" << "ID" << "\t\t" << "tipologia" << "\t\t" << "valor" << "\t\t" << "nome" << "\n";
		ifstream myfile("consulta8.txt");
		myfile.seekg(0);
		for (i = 0; i < size; i++)
		{
			cout << "\n\n";
			myfile.read((char*)&d, sizeof(d));
			d.mostrar_tudo(d);
		}
		cout << "********************************************************************************";
	}
}
int  mostrar_consulta_data()
{
	long int size = 0;
	size = get_size_of_the_file();
	int i = 0, id, id1, count = 0;
	consulta d1;
	size = size / (sizeof(d1));
	if (size == 0)
	{
		cout << "\nVazio!!!";
		cout << "\n";
	}
	else
	{

		cout << "\nEscreva o id da consulta pretendida :";
		cin >> id;
		ifstream myfile1("consulta8.txt");
		for (i = 0; i < size; i++)
		{
			myfile1.clear();
			myfile1.read((char*)&d1, sizeof(d1));
			id1 = d1.get_ID();
			if (id == id1)
			{
				count = 1;
				d1.mostrar_info(d1);
				cout << "\n";
				cout << "\n";
				system("PAUSE");
				cout << "\n";
				break;
			}

		}

		myfile1.close();
		return(count);
	}
}

void modificar_consulta_data()
{
	int id1;
	long int size = 0;
	size = get_size_of_the_file();
	int i = 0, count = 0, id;
	consulta d2;
	size = size / (sizeof(d2));
	if (size == 0)
	{
		cout << "\nVazio!!!\n";
		cout << "\nNada a modificar!!!";
		cout << "\n\n";
		system("PAUSE");
	}
	else
	{
		cout << "\nEscreva o id da consulta:";
		cin >> id1;
		ifstream myfile2("consulta8.txt");
		for (i = 0; i < size; i++)
		{
			myfile2.clear();
			myfile2.read((char*)&d2, sizeof(d2));
			id = d2.get_ID();
			if (id == id1)
			{
				size = myfile2.tellg();
				size = size - sizeof(d2);
				count = 1;
				d2.mostrar_info(d2);
				cout << "\n\n";
				system("PAUSE");
				cout << "\n";
				cout << "\nEscolha o campo a modificar\n";
				cout << "\n1.Nome\n2.Diagnostico\n3.Tipologia\n";
				cout << "4.Data\n5.Preco\n";
				int opt2;
				cout << "\nescolha:";
				cin >> opt2;
				switch (opt2)
				{
				case 1:
					d2.modificar_consulta(d2, opt2, size);
					break;
				case 2:
					d2.modificar_consulta(d2, opt2, size);
					break;
				case 3:
					d2.modificar_consulta(d2, opt2, size);
					break;
				case 4:
					d2.modificar_consulta(d2, opt2, size);
					break;
				case 5:
					d2.modificar_consulta(d2, opt2, size);
					break;
				case 6:
					d2.modificar_consulta(d2, opt2, size);
					break;
				case 7:
					d2.modificar_consulta(d2, opt2, size);
					break;
				default:
					cout << "\nerro ";
				}
				break;
			}
		}

		myfile2.close();
		if (count == 0)
		{
			cout << "\nNao existe !!!";
			cout << "\n";
			system("PAUSE");
		}
	}
}

void eliminar_conteudos()
{
	ofstream myfile("consulta8.txt");
	myfile.close();
}
void eliminar_conteudos1()
{
	ofstream myfile("paciente11.txt");
	myfile.close();
}

void eliminar_consulta_data()
{
	long int size;
	size = get_size_of_the_file();
	consulta d;
	size = size / (sizeof(d));
	if (size == 0)
	{
		cout << "\nVazio!!!";
		cout << "\n\nNada a eliminar!!!";
		cout << "\n";
	}
	else
	{
		ifstream  myfile6("consulta8.txt");
		ofstream myfile7("temp1.txt");
		int id, count = 0, id1, i;
		cout << "\nEscreva o ID da consulta a eliminar :";
		cin >> id;
		for (i = 0; i < size; i++)
		{
			myfile6.read((char*)&d, sizeof(d));
			id1 = d.get_ID();
			if (id != id1)
			{
				myfile7.write((char*)&d, sizeof(d));
			}
			else
			{
				count = 1;

			}
		}
		myfile6.close();
		myfile7.close();
		ofstream myfile9("consulta8.txt");
		ifstream myfile8("temp1.txt");
		for (i = 0; i < size - 1; i++)
		{
			myfile8.read((char*)&d, sizeof(d));
			myfile9.write((char*)&d, sizeof(d));
		}
		if (count == 0)
		{
			cout << "\nNada encontrado";
			cout << "\n\n";
			system("PAUSE");
		}
		else
		{
			cout << "\nEliminado com sucesso\n";
		}
	}
}


long int get_size_of_the_file()
{
	long int size = 0;
	ifstream ifile("consulta8.txt");
	ifile.seekg(0, ios::end);
	size = ifile.tellg();
	ifile.close();
	return(size);

}

void adicionar_paciente_data()
{
	paciente p;
	ofstream myfile("paciente11.txt", ios::in | ios::app);
	p.get_info();
	myfile.write((char*)&p, sizeof(p));
	myfile.close();
}
void mostrar1()
{
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0;
	paciente p;
	size = size / (sizeof(p));
	if (size == 0)
	{
		cout << "\nDatabase Empty!!!";
		cout << "\n";
	}
	else
	{
		cout << "\n";
		cout << "********************************************************************************";
		cout << "\n\t\t\tDetalhes dos pacientes\n";
		cout << "********************************************************************************";
		cout << "ID" << "\t" << "name" << "id consulta" << "\n";
		ifstream myfile("paciente11.txt");
		myfile.seekg(0);
		for (i = 0; i < size; i++)
		{
			cout << "\n\n";
			myfile.read((char*)&p, sizeof(p));
			p.mostrar_tudo(p);
		}
		cout << "********************************************************************************";
	}
}

int mostrar_paciente_data()
{
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0, id, id1, count1 = 0;
	paciente p1;
	size = size / (sizeof(p1));
	if (size == 0)
	{
		cout << "\nVazio!!!";
		cout << "\n";
	}


	else
	{
		cout << "\nId do paciente :";
		cin >> id;
		ifstream myfile1("paciente11.txt");
		for (i = 0; i < size; i++)
		{
			myfile1.clear();
			myfile1.read((char*)&p1, sizeof(p1));
			id1 = p1.get_ID();
			if (id == id1)
			{
				count1 = 1;

				p1.mostrar_info(p1);
				cout << "\n\n";
				system("PAUSE");
				cout << "\n";
				break;
			}
		}
		myfile1.close();
		return(count1);

	}
}

void atribuir_paciente()
{
	paciente p;
	int id;
	long int size;
	size = get_size_of_the_file1();
	int i = 0, count = 0, id1;
	size = size / (sizeof(p));
	if (size == 0)
	{
		cout << "\nVazio!!\n";
		cout << "\nAdicionar informacao primeiro!!!";
		cout << "\n\n";
		system("PAUSE");
	}
	else
	{
		cout << "\nID do paciente  :";
		cin >> id;
		ifstream myfile("paciente11.txt");
		myfile.seekg(0);
		for (i = 0; i < size; i++)
		{
			myfile.read((char*)&p, sizeof(p));
			id1 = p.get_ID();
			if (id == id1)
			{
				count = 1;
				size = myfile.tellg();
				size = size - sizeof(p);
				p.atribuir_paciente_consulta(p, size);
				break;
			}
		}
		if (count == 0)
		{
			system("CLS");
			cout << "********************************************************************************";
			cout << "\nNAO EXISTE\n";
			cout << "********************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
	}
}


void modificar_paciente_data()
{
	int id1;
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0, count = 0, id;
	paciente p2;
	size = size / (sizeof(p2));
	if (size == 0)
	{
		cout << "\nVazio!!!\n";
		cout << "\nNada a moficiar!!!";
		cout << "\n\n";
		system("PAUSE");
	}
	else
	{
		cout << "\nEscreva o id a modificar :";
		cin >> id1;
		ifstream myfile2("paciente11.txt");
		myfile2.seekg(0);
		for (i = 0; i < size; i++)
		{
			myfile2.read((char*)&p2, sizeof(p2));
			id = p2.get_ID();
			if (id == id1)
			{
				size = myfile2.tellg();
				size = size - sizeof(p2);
				count = 1;
				p2.mostrar_info(p2);
				cout << "\n";
				system("PAUSE");
				cout << "\n";
				cout << "\ncampos a mudar\n";
				cout << "\n1.Nome\n";
				cout << "\n";
				cout << "\n\n";
				cout << "\n";
				cout << "2.Valor a pagar";
				int opt2;
				cout << "\nEscolha o que quer modificar :";
				cin >> opt2;
				switch (opt2)
				{
				case 1:
					p2.modificar_info(p2, opt2, size);
					break;
				case 2:
					p2.modificar_info(p2, opt2, size);
					break;

				default:
					cout << "\nerro";
				}
				break;
			}
		}
		myfile2.close();
		if (count == 0)
		{
			cout << "\nNao existe!!!";
			cout << "\n";
			system("PAUSE");

		}
	}

}
void eliminar_paciente_data()
{
	long int size;
	size = get_size_of_the_file1();
	paciente p;
	size = size / (sizeof(p));
	if (size == 0)
	{
		cout << "\nVazio!!!";
		cout << "\n\nNao existe!!!";
		cout << "\n";
	}
	else
	{
		ifstream myfile6("paciente11.txt");
		ofstream myfile7("temp4.txt");
		int id, count = 0, id1, i;
		cout << "\nID do paciente a eliminar :";
		cin >> id;
		for (i = 0; i < size; i++)
		{
			myfile6.read((char*)&p, sizeof(p));
			id1 = p.get_ID();
			if (id != id1)
			{
				myfile7.write((char*)&p, sizeof(p));
			}
			else
			{
				count = 1;

			}
		}
		myfile6.close();
		myfile7.close();
		ofstream myfile9("paciente11.txt");
		ifstream myfile8("temp4.txt");
		for (i = 0; i < size - 1; i++)
		{
			myfile8.read((char*)&p, sizeof(p));
			myfile9.write((char*)&p, sizeof(p));
		}

		if (count == 0)
		{
			cout << "\nNada encontrado ";
			cout << "\n\n";

		}

		else
		{
			cout << "\nEliminado com sucesso ";
			cout << "\n\n";

		}
	}


}
long int get_size_of_the_file1()
{
	long int size = 0;
	ifstream ifile("paciente11.txt");
	ifile.seekg(0, ios::end);
	size = ifile.tellg();
	ifile.close();
	return(size);
}

int numero()
{
	long int size;
	paciente p;
	size = get_size_of_the_file1();
	size = size / (sizeof(p));
	return(size);

}

void relatorio()
{
	paciente p;
	int id, id1, count = 0;
	long int size;
	size = get_size_of_the_file1();
	size = size / (sizeof(p));
	if (size == 0)
	{
		cout << "\nVAZIO!!!";
		cout << "\nAdicionar informacao de pacientes primeiro!!!";
		cout << "\n\n";
		system("PAUSE");
	}
	else
	{

		cout << "\nID do paciente :";
		cin >> id;
		ifstream myfile1("paciente11.txt");
		for (int i = 0; i < size; i++)
		{
			myfile1.clear();
			myfile1.read((char*)&p, sizeof(p));
			id1 = p.get_ID();
			if (id == id1)
			{
				count = 1;

				p.relatorio1(p);
				break;
			}

		}
		if (count == 0)
		{
			cout << "\nVazio!!!";
		}
	}
}
void conta()
{
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0, id, id1, count1 = 0;
	paciente p1;
	size = size / (sizeof(p1));
	if (size == 0)
	{
		cout << "\nVazio!!!";
		cout << "\n";
	}


	else
	{
		cout << "\nEscreva o id do paciente :";
		cin >> id;
		ifstream myfile1("paciente11.txt");
		for (i = 0; i < size; i++)
		{
			myfile1.clear();
			myfile1.read((char*)&p1, sizeof(p1));
			id1 = p1.get_ID();
			if (id == id1)
			{
				count1 = 1;

				p1.preco1(p1);
				break;
			}
		}
		if (count1 == 0)
		{
			cout << "\nVazio!!!";
		}
		myfile1.close();

	}
}
