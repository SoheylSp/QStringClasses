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

    }else if(myArguments.contains("endsWith")) {

        if(! myArguments.contains("str")){

            qCritical()<<"need a string\n";

        }

        QString myStr = myArguments["str"].toString();

        if(myStr.endsWith(".")){

            myStr.fill('*');
        }else if (myStr.endsWith("-")) {

            myStr.fill('#');

        }else {

            myStr.fill('$');
        }

    }else if (myArguments.contains("split")) {

        if(!myArguments.contains("str") || !myArguments.contains("splitChar")){

            qCritical()<<"a str and a split character needed\n";

        }

        QString myStr = myArguments["str"].toString();
        QChar mySplitChar = myArguments["splitChar"].toChar();

        QStringList myStrList = myStr.split(mySplitChar);

        qDebug()<<"The Splited List is : " << myStrList ;


    }else if (myArguments.contains("replace")) {

        if(! myArguments.contains("str") || ! myArguments.contains("replaceThis") || ! myArguments.contains("replaceWith")){

            qCritical()<<"a srting & a World which must replace(replaceThis) and a word which must replace with it(replaceWith) is required ()";

        }

        QString myStr = myArguments["str"].toString();
        QString replaceThis = myArguments["replaceThis"].toString();
        QString replaceWith = myArguments["replaceWith"].toString();

        QString myNewStr = myStr.replace(replaceThis,replaceWith);

        qDebug()<<"here is the replaced string : \n";

        qDebug()<<myNewStr;
    }else if (myArguments.contains("remove")) {

        if(!myArguments.contains("str") || !myArguments.contains("removeThis")){
            qCritical()<<"a string and a remove word (removeThis) is required\n";
        }

        QString myStr = myArguments["str"].toString();
        QString removeThis = myArguments["removeThis"].toString();
        QString myNewStr = myStr.remove(removeThis);

        qDebug()<<"New Str after removing is : \n";

        qDebug()<<myNewStr;

    }else if (myArguments.contains("prepend")) {

        if(! myArguments.contains("str") || ! myArguments.contains("prependThis")){

            qCritical()<<"a string and another one to prepend is required\n";
        }

        QString myStr = myArguments["str"].toString();
        QString prependThis = myArguments["prependThis"].toString();

        QString myNewStr = myStr.prepend(prependThis);

        qDebug()<<"new str is : \n";
        qDebug()<<myNewStr;

    }else if (myArguments.contains("whereIsThis")) {

        if(! myArguments.contains("str") || ! myArguments.contains("findThis")){

            qCritical()<<"a string and a word(findThis) needed\n ";

        }

        QString myStr =  myArguments["str"].toString();
        QString findThis = myArguments["findThis"].toString();

        int firstOccurrence = myStr.indexOf(findThis);

        qDebug()<<"the number of first occurrence of you'r word is : " << firstOccurrence << "\n";


    }else if (myArguments.contains("insert")) {

        if(! myArguments.contains("str") || ! myArguments.contains("insertThis") || ! myArguments.contains("atPosition")){

            qCritical()<<"a str & an insert word(insertThis) & a number (atPosition) needed";

        }

        QString myStr = myArguments["str"].toString();
        QString insertThis = myArguments["insertThis"].toString();
        int atPosition = myArguments["atPosition"].toInt();

        QString myNewStr = myStr.insert(atPosition,insertThis);

        qDebug()<<"the string after insertion is :\n";
        qDebug()<<myNewStr;

    }else if (myArguments.contains("lastIndexOf")) {



        if(! myArguments.contains("str") || ! myArguments.contains("findThis")){

            qCritical()<<"a string and a word(findThis) needed\n ";

        }

        QString myStr =  myArguments["str"].toString();
        QString findThis = myArguments["findThis"].toString();

        int lastOccurrence = myStr.lastIndexOf(findThis);

        qDebug()<<"the number of last occurrence of you'r word is : " << lastOccurrence << "\n";


    }else if (myArguments.contains("UpperOrLower")) {

        if(!myArguments.contains("str")){

            qCritical()<<"a str is needed" ;

        }

        QString myStr = myArguments["str"].toString();

        QChar charArray[myStr.length()];

        //assign myStr to an array

        for(int i = 0 ; i < myStr.length() ; ++i){
            charArray[i] = myStr.at(i);
        }

        //chack characters

        for(int i = 0 ; i < myStr.length() ; ++ i){

            if(charArray[i].isUpper()){

                qDebug()<<"the character at " << i << "isUpper :" <<charArray[i]<<"\n";

            }else if (charArray[i].isLower()) {

                qDebug()<<"the character at" << i << "isLower : "<< charArray[i] << "\n";

            }else {

                qDebug()<<"the character at index " << i << "is not a letter"<<charArray[i]<<"\n";
}

        }

    }else if (myArguments.contains("isEmpty")) {

        if(!myArguments.contains("str")){

            qCritical()<<"a string is required";

        }

        QString myStr = myArguments["str"].toString();
        bool isEmpty = myStr.isEmpty() ;

        if(isEmpty == true){

            qDebug()<<"the string is empty";

        }else {

            qDebug()<<"the string is not empty";
}

}else if (myArguments.contains("triimed")) {

        if(!myArguments.contains("str")){

            qCritical()<<"a string is required";

        }
        QString myStr = myArguments["str"].toString();

        QString myTrimmedStr = myStr.trimmed();

        qDebug()<<"the trimmed string is : \n";
        qDebug()<<myTrimmedStr;

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
