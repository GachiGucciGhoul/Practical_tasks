#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>

std::string pshe (std::string str)
{
    std::stack<char> stack;
    std::string string;

        int i = 0;
        while (i<str.length())
        {

           while (((48<=str[i])&&(str[i]<=57))||(str[i]==46)) // ïðîâåðêà íà ÷èñëà (46- òî÷êà äëÿ äåñÿòè÷íûé)
           {
               string.push_back(str[i]);

               if (str[i+1]==' ') string.push_back(' ');
                i++;
           }

           if (str[i]==40) //ïðîââåðêà íà îòêðûâàþùèþ ñêîáêó
           {
               stack.push(str[i]);
               i++;
           }

           if (str[i]==41)  // )
           {
               if (!stack.empty())
               {
               while (stack.top()!= 40) {
                   string.push_back(stack.top());
                   string.push_back(' ');
                   stack.pop();
               }
               stack.pop();
               }
               i++;
       }

       if ((str[i]==43)||(str[i]==45)) // + -
       {

           while ((!stack.empty())&&((stack.top()==43)||(stack.top()==45)))
           {
               string.push_back(stack.top());
               string.push_back(' ');
               stack.pop();
           }

           stack.push(str[i]);
           i++;
       }

       if ((str[i]==42)||(str[i]==47)) // * /
       {


           while ((!stack.empty())&&((stack.top()!=43)&&(stack.top()!=45)&&(stack.top()!=40))) {
               string.push_back(stack.top());
               string.push_back(' ');
               stack.pop();

           }
           stack.push(str[i]);
           i++;
       }

       if (str[i]==94) // ^
       {
           stack.push(str[i]);
           i++;
       }

    i++;
    }

    while (!stack.empty())
    {
        string.push_back(' ');
        string.push_back(stack.top());
        stack.pop();
    }

    return string;
}

double calculate_RPN (std::string RPN)
{
    std::stack<double> stack;
    std::string storage;

    int i = 0;
    double a, b, result=0;
    char oper;

    while (i<RPN.length())
    {
        if ( ('0'<=RPN[i]) && (RPN[i]<='9') )
        {
            while ( ( ('0'<=RPN[i]) && (RPN[i]<='9') ) || (RPN[i]=='.') ) // ïðîâåðêà íà ÷èñëà (46- òî÷êà äëÿ äåñÿòè÷íûé)
            {
                storage.push_back(RPN[i]);
                i++;
            }
            stack.push(std::stod(storage));
            storage = "";
        }
        else if (RPN[i] == ' ')
           i++;
        else
        {
            oper = RPN[i];
            i++;
            b = stack.top();
            stack.pop();
            a = stack.top();
            stack.pop();

            switch (oper) {
            case '+':
               result = a + b;
               stack.push(result);
               break;
            case '-':
               result = a - b;
               stack.push(result);
               break;
            case '*':
               result = a * b;
               stack.push(result);
               break;
            case '/':
               result = a / b;
               stack.push(result);
               break;
            case '^':
               result = pow(a, b);
               stack.push(result);
               break;
            default:
                i++;
                break;
            }
        }
    }
    return stack.top();
}

int main()
{

    std::string str;
    std::getline(std::cin, str);
    std::cout<<pshe(str)<<'\n'<<calculate_RPN(pshe(str))<<'\n';

//    for (int i =0; i<=255; i++)
//    {
//        std::cout<<i<<'='<<(char)i<<'\n';
//    }
}


//40=(
//41=)
//48=0
//49=1
//50=2
//51=3
//52=4
//53=5
//54=6
//55=7
//56=8
//57=9
//42=*
//43=+
//45=-
//46=.
//47=/
//94=^
