#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class expres
{
	string expression;

public:
	void Get_prefix()
	{
		char stek[1000];
		int i = -1, j = 0;
		int k = 0;
		string temp;
		temp.empty();

		do
		{
			j++;
			if ((expression.size() - j == -1) && (i != -1))
			{
				break;
			}
			if (is_digit(expression[expression.size() - j]) || expression[expression.size() - j] == '.')
			{
				while ((!is_it_an_operator(expression[expression.size() - j])) && (is_digit(expression[expression.size() - j]) || expression[expression.size() - j] == '.'))
				{
					temp.push_back(expression[expression.size() - j]);
					j++;
					if (j > expression.size()) break;
				}
				if (j > expression.size()) j++;
				temp.push_back(' ');
				j--;
			}
			else if (is_it_an_operator(expression[expression.size() - j]))
			{
				if (expression[expression.size() - j] == ')')
				{
					i++;
					stek[i] = expression[expression.size() - j];
				}
				else if (expression[expression.size() - j] == '(')
				{
					char s = stek[i];
					i--;

					do
					{
						temp.push_back(s);
						s = stek[i];
						i--;
					} while (s != ')');
				}
				else
				{
					if (i > -1)
					{
						if (priority(expression[expression.size() - j]) <= priority(stek[i]))
						{
							temp.push_back(stek[i]);
							i--;
						}
					}
					i++;
					stek[i] = expression[expression.size() - j];
				}

			}
			else if (expression[expression.size() - j] == ' ')
			{

			}
			else if (expression[expression.size() - j] == 't')
			{
				if (expression[expression.size() - j - 1] == 'r')
				{
					if (expression[expression.size() - j - 2] == 'q')
					{
						if (expression[expression.size() - j - 3] == 's')
						{
							for (int q = 0; q < 4; q++)
							{
								temp.push_back(expression[expression.size() - j]);
								j++;
							}
						}
						else
						{
							throw out_of_range("wrong input");
						}
					}
					else
					{
						throw out_of_range("wrong input");
					}
				}
				else
				{
					throw out_of_range("wrong input");
				}
			}
			else if (expression[expression.size() - j] == 'g')
			{
				if (expression[expression.size() - j - 1] == 't')
				{
					if (expression[expression.size() - j - 2] == 'c')
					{
						for (int q = 0; q < 3; q++)
						{
							temp.push_back(expression[expression.size() - j]);
							j++;
						}
					}
					else
					{
						for (int q = 0; q < 2; q++)
						{
							temp.push_back(expression[expression.size() - j]);
							j++;
						}
					}
				}
				else if (expression[expression.size() - j - 1] == 'o')
				{
					if (expression[expression.size() - j - 2] == 'l')
					{
						for (int q = 0; q < 3; q++)
						{
							temp.push_back(expression[expression.size() - j]);
							j++;
						}
					}
				}
				else
				{
					throw out_of_range("wrong input");
				}
			}
			else if (expression[expression.size() - j] == 's')
			{
				if (expression[expression.size() - j - 1] == 'o')
				{
					if (expression[expression.size() - j - 2] == 'c')
					{
						for (int q = 0; q < 3; q++)
						{
							temp.push_back(expression[expression.size() - j]);
							j++;
						}
					}
					else
					{
						throw out_of_range("wrong input");
					}
				}
				else
				{
					throw out_of_range("wrong input");
				}
			}
			else if (expression[expression.size() - j] == 'n')
			{
				if (expression[expression.size() - j - 1] == 'i')
				{
					if (expression[expression.size() - j - 2] == 's')
					{
						for (int q = 0; q < 3; q++)
						{
							temp.push_back(expression[expression.size() - j]);
							j++;
						}
					}
					else
					{
						throw out_of_range("wrong input");
					}
				}
				else if (expression[expression.size() - j - 1] == 'l')
				{
					for (int q = 0; q < 2; q++)
					{
						temp.push_back(expression[expression.size() - j]);
						j++;
					}

				}
				else
				{
					throw out_of_range("wrong input");
				}
			}
			else if (expression[expression.size() - j] == 'i')
			{
				if (expression[expression.size() - j - 1] == 'p')
				{
					for (int i = 0; i < 2; i++)
					{
						temp.push_back(expression[expression.size() - j]);
						j++;
					}
					temp.push_back(' ');
				}
				else
				{
					throw out_of_range("wrong input");
				}
			}
			else if (expression[expression.size() - j] == 'e')
			{
				temp.push_back(expression[expression.size() - j]);
				temp.push_back(' ');
			}
			else
			{
				throw domain_error("wrong input");
			}
		} while (expression.size() - j != -1);

		while (i != -1)
		{
			if (stek[i] == '(' || stek[i] == ')')
			{
				i--;
			}
			else
			{
				temp.push_back(stek[i]);
				i--;
			}
		}

		expression.resize(temp.size());
		int n = temp.size();

		for (int l = 0; l < temp.size(); l++)
		{
			expression[l] = temp[n - 1];
			n--;
		}

	}

	void string_print()
	{
		cout << expression;
	}

	bool is_it_an_operator(char elem)
	{
		switch (elem)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case ')':
		case '(':
			return 1;
			break;
		default:
			return 0;
		}
	}

	int priority(char elem)
	{
		switch (elem)
		{
		case'+':
		case'-':
			return 1;
			break;
		case'*':
		case'/':
			return 2;
			break;
		case'^':
			return 3;
			break;
		case')':
		case'(':
			return 0;
			break;

		}
	}
	double Calculate()
	{
		double result = 0;
		double stek[100];
		int i = -1;
		int j = 1;

		while (expression.size() - j != -1)
		{
			if ((is_digit(expression[expression.size() - j]) == true) || (expression[expression.size() - j] == '.'))
			{
				string temper; temper.empty();
				string temper2; temper2.empty();
				int count1, count2 = 1;

				while ((!is_it_an_operator(expression[expression.size() - j])) && (is_digit(expression[expression.size() - j]) || expression[expression.size() - j] == '.'))
				{
					temper += expression[expression.size() - j];
					j++;
					if (j == expression.length()) break;
				}
				count1 = temper.size();
				for (count1; count1 > 0; count1--)
				{
					temper2.push_back(temper[temper.size() - count2]);
					count2++;
				}

				i++;
				stek[i] = stod(temper2);
				j--;
			}
			else if (is_it_an_operator(expression[expression.size() - j]))
			{
				double amount = stek[i];
				i--;
				double amount2 = stek[i];
				i--;

				switch (expression[expression.size() - j])
				{
				case '+': result = amount + amount2; break;
				case '-': result = amount - amount2; break;
				case '*': result = amount * amount2; break;
				case '/': result = amount / amount2; break;
				case '^': result = pow(amount, amount2); break;
				}
				i++;
				stek[i] = result;
			}
			else if (expression[expression.size() - j] == ' ')
			{

			}
			else if (expression[expression.size() - j] == 'i')
			{
				string val;
				val.empty();
				for (int i = 0; i < 2; i++)
				{
					val.push_back(expression[expression.size() - j]);
					j++;
				}
				i++;
				stek[i] = 3.14;
				j--;
			}
			else if (expression[expression.size() - j] == 'e')
			{
				string val;
				val.empty();
				val.push_back(expression[expression.size() - j]);
				i++;
				stek[i] = 2.7182818284;
			}
			else if (expression[expression.size() - j] == 's')
			{
				if (expression[expression.size() - j - 1] == 'o')
				{
					double value = stek[i];
					i--;

					result = cos(value);

					i++;
					stek[i] = result;
					j++; j++;
				}
			}
			else if (expression[expression.size() - j] == 'n')
			{
				if (expression[expression.size() - j - 1] == 'i')
				{
					double value = stek[i];
					i--;

					result = sin(value);

					i++;
					stek[i] = result;
					j++; j++;
				}
				else if (expression[expression.size() - j - 1] == 'l')
				{
					double value = stek[i];
					i--;

					result = log(value);

					i++;
					stek[i] = result;
					j++;
				}
			}
			else if (expression[expression.size() - j] == 'g')
			{
				if (expression[expression.size() - j - 1] == 't')
				{
					if (expression[expression.size() - j - 2] == 'c')
					{
						double value = stek[i];
						i--;

						result = cos(value) / sin(value);

						i++;
						stek[i] = result;
						j++; j++;
					}
					else
					{
						double value = stek[i];
						i--;

						result = tan(value);

						i++;
						stek[i] = result;
						j++;
					}
				}
				else if (expression[expression.size() - j - 1] == 'o')
				{
					if (expression[expression.size() - j - 2] == 'l')
					{
						double value = stek[i];
						i--;

						result = log10(value);

						i++;
						stek[i] = result;
						j++; j++;
					}
				}
			}
			else if (expression[expression.size() - j] == 't')
			{
				if (expression[expression.size() - j - 1] == 'r')
				{
					if (expression[expression.size() - j - 2] == 'q')
					{
						if (expression[expression.size() - j - 3] == 's')
						{
							double value = stek[i];
							i--;

							result = sqrt(value);

							i++;
							stek[i] = result;
							j++; j++; j++;

						}
					}
				}
			}
			j++;
		}
		expression.empty();
		return stek[i];
	}

	bool is_digit(char elem)
	{
		switch (elem)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return true;
		default:
			return false;
		}
	}

	void set_Exp(string rt)
	{
		expression.resize(rt.size());
		expression = rt;

	}
	string return_Exp()
	{
		return expression;
	}
};
