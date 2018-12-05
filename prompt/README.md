# prompt

## sample image
```
======================================
quit : q
sample : t
======================================
```
"quit", "sample" ... name of user commands  
"q", "t" ... key input to invoke the command

## sample code
Please see "main.cpp".

## How to use "prompt"?

1. create the function like "void function(string arg);"
2. create the object of Clauncher.
3. Clauncher::append() such as below:
```
launcher.append(new Ccommand{"sample", "t",
                               new function<void(string)>{template_function}});
```
"sample" -> name of user command.  
"t" -> key input to invoke the command.

4. invoke Clauncher::exec().

## Class diagram
```puml
@startuml
skinparam classAttributeIconSize 0

class Clauncher{
    {abstract}+void exec()
    +void append(Ccommand *com)
}


class Ccommand{
  +Ccommand(string name, string key, function<void(string)> *f)
}

 Clauncher o- Ccommand
 @enduml
```

## Sequence diagram
```puml
@startuml
actor user

main -> Clauncher : create
activate main
activate Clauncher
Clauncher --> main : object
deactivate Clauncher

main -> Ccommand : create
activate Ccommand
Ccommand --> main : object
deactivate Ccommand

main -> Clauncher : append(Ccommand obj)
activate Clauncher
Clauncher --> main
deactivate Clauncher

main -> Clauncher : exec
activate Clauncher
Clauncher --> main
deactivate Clauncher

====

user --> main : key input
main --> Clauncher : key input
activate Clauncher
Clauncher -> Ccommand : invoke the function
activate Ccommand
Ccommand --> Clauncher
deactivate Ccommand
Clauncher --> main
deactivate Clauncher
@enduml
```
