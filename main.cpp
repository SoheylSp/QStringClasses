#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
QVariantMap readArguments(QStringList arguments);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVariantMap myArguments = readArguments(a.arguments());

    if(myArguments.contains("append")){

        if(! myArguments.contains("firstStr") || ! myArguments.contains("secondStr")){

            qCritical()<<"two strings needed for this\n";

        }

        QString firstStr = myArguments["firstStr"].toString();
        QString secondStr = myArguments["secondStr"].toString();

        QString appendedStr = firstStr.append(secondStr);

        qDebug()<<"First String is : " << firstStr <<"\n";
        qDebug()<<"Second String is : " << secondStr <<"\n";
        qDebug()<<"the appended String is: " << appendedStr <<"\n";
    }else if(myArguments.contains("arg")){


        if(! myArguments.contains("argString") || !myArguments.contains("argValue")){

            qCritical()<<"argString & argValue required for arg command\n";

        }

        QString argString = myArguments["argString"].toString();
        QString argValue = myArguments["argValue"].toString();

        //Using QString::arg()

        QString formatedString = argString.arg(argValue);

        qDebug()<<"Original String : " << argString << "\n" ;
        qDebug()<<"Formated String : " << formatedString<<"\n";


    }else if (myArguments.contains("compare")) {

        if(!myArguments.contains("firstStr") || ! myArguments.contains("secondStr")){

            qCritical()<<"Two strings are needed\n";

        }

        QString firstStr = myArguments["firstStr"].toString();
        QString secondStr = myArguments["secondStr"].toString();

        int compareNumber = QString::compare(firstStr,secondStr);

        if(compareNumber == 0){

            qDebug()<<"Strings are EQUAL\n";
        }else if (compareNumber<0) {

            qDebug()<<"First String is LESS than second one\n";
        }else if (compareNumber>0) {

            qDebug()<<"First String is GREATER than second one\n";
        }

    }else if (myArguments.contains("counter")) {


        if(! myArguments.contains("targetStr") || ! myArguments.contains("targetWord")){

            qCritical()<<"A target string and a target word needed\n";

        }

        QString targetStr (myArguments["targetStr"].toString());
        QString targetWord(myArguments["targetWord"].toString());

        int countNumber = targetStr.count(targetWord);

        qDebug()<<"There is " << countNumber << "of" << targetWord << "in your string\n";

}else if (myArguments.contains("length")) {

        if(!myArguments.contains("str")){

            qCritical()<<"you need to input your str";
        }

        QString str = myArguments["str"].toString();
        int strLength = str.length();
        qDebug()<<"your string length is : " << strLength<<"\n";

}




    return a.exec();
}


QVariantMap readArguments(QStringList arguments){

    QVariantMap argumentsMap;

    for(int i = 1 ; i < arguments.length() ; ++i){

        QString argument = arguments[i];

        if(arguments.startsWith("--")){

            QString key = argument.mid(2);
            if(i+1 < arguments.length()){

                QString value = arguments[i+1];

                if(value.startsWith("--")){

                    //if the next argument is another option , assume true for this option
                    argumentsMap[key] = true ;

                }else{

                    //If the next argument is not another option , its a value for this option
                    argumentsMap[key] = value ;

                    ++i ;
                }

            }else {

                //If there is no next argument ,  assume true for this  option

                argumentsMap[key] = true ;

            }

        }


    }

    return argumentsMap;

}
