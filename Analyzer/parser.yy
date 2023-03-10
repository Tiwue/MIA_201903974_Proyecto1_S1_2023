%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.2"
%defines
%define api.parser.class {class_parser}
%define api.token.constructor
%define api.namespace {yy}
%define api.value.type variant
%define parse.assert
%code requires

{
#include <string>
#include <stdio.h>

class parser_driver;
}

%param { parser_driver& driver }
%locations
%define parse.trace
%define parse.error verbose
%code

{
#include "driver.h"
#include "../Utils/Builder.h"
#include "../Utils/CommandHandler.cpp"
#include <iostream>
#include <vector>

std::vector<parameter> parameters;
struct command x;

}
%define api.token.prefix {TOK_}

//Listado de Terminales
%token <std::string> EQUAL "tk_EQUAL"
%token <std::string> FIT "_FIT"
%token <std::string> UNIT "_UNIT"
%token <std::string> PATH "_PATH"
%token <std::string> SIZE "_SIZE"
%token <std::string> TYPE "_TYPE"
%token <std::string> TYPE2 "_TYPE2"

%token <std::string> DELETE "_DELETE"
%token <std::string> NAME "_NAME"
%token <std::string> ADD "_ADD"
%token <std::string> ID "_ID"
%token <std::string> FS "_FS"

%token <std::string> LOGIN "_login"
%token <std::string> LOGOUT "_logout"
%token <std::string> MKGRP "_MKGRP"
%token <std::string> RMGRP "_RMGRP"
%token <std::string> MKUSR "_MKUSR"
%token <std::string> RMUSR "_RMUSR"
%token <std::string> CHGRP "_CHGRP"

%token <std::string> USER "_USER"
%token <std::string> PWD "_PWD"
%token <std::string> GRP "_GRP"

%token <std::string> MKFILE "_MKFILE"
%token <std::string> CHOWN "_CHOWN"
%token <std::string> CHMOD "_CHMOD"
%token <std::string> CAT "_CAT"
%token <std::string> RM "_RM"
%token <std::string> EDIT "_EDIT"
%token <std::string> REN "_REN"
%token <std::string> MV "_MV"
%token <std::string> CP "_CP"
%token <std::string> MKDIR "_MKDIR"
%token <std::string> FIND "_FIND"
%token <std::string> LOSS "_LOSS"
%token <std::string> RECOVERY "_RECOVERY"

%token <std::string> R "_R"
%token <std::string> FILEN "_FILEN"
%token <std::string> DEST "_DEST"
%token <std::string> P "_P"
%token <std::string> CONT "_CONT"
%token <std::string> UGO "_UGO"
%token <std::string> STDIN "_STDIN"

%token <std::string> RUTA "_RUTA"



%token <std::string> MKDISK "_MKDISK"
%token <std::string> RMDISK "_RMDISK"
%token <std::string> FDISK "_FDISK"
%token <std::string> MOUNT "_MOUNT"
%token <std::string> UMOUNT "_UMOUNT"
%token <std::string> MKFS "_MKFS"

%token <std::string> STRING_DOUBLE "tk_string_d"
%token <std::string> STRING_SINGLE "tk_string_s"
%token <std::string> PATH_DIR "tk_path"
%token <std::string> RUN_EXEC "_exec"
%token <std::string> RUN_REPORT "_rep"
%token <std::string> IDENTIFICADOR "tk_identifier"
%token <std::string> PATTERN "tk_pattern"
%token <std::string> NUMERO "tk_number"
%token FIN 0 "eof"

//Listado de No Terminales
%type E
%type PARAMS
%type DISCOS
%type EXEC
%type REPORT
%type <std::string> PARAM
%type <std::string> BOOLEAN_PARAM
%type <std::string> STRING
%type <std::string> DATA

%%

%start INICIO;

INICIO: E "eof"   {return CommandHandler(x);}
      | "eof"
;

STRING: "tk_string_d" {$$=$1.substr(1, $1.size() - 2);}
      | "tk_string_s" {$$=$1.substr(1, $1.size() - 2);}
;

DATA: STRING {$$=$1;}
    | "tk_number" {$$=$1;}
    | "tk_path" {$$=$1;}
    | "tk_identifier" {$$=$1;}
    | "tk_pattern" {$$=$1;}
;

E: EXEC
 | DISCOS
 | REPORT
;

EXEC: "_exec" PARAMS {x = newCommand("__EXEC",parameters);}
;

DISCOS: "_MKDISK" PARAMS {x = newCommand("__MKDISK",parameters);}
        | "_RMDISK" PARAMS {x = newCommand("__RMDISK",parameters);}
        | "_FDISK" PARAMS {x = newCommand("__FDISK",parameters);}
        | "_MOUNT" PARAMS {x = newCommand("__MOUNT",parameters);}
;

REPORT: "_rep" PARAMS {x = newCommand("__REP",parameters);}
;

PARAMS: PARAMS PARAM "tk_EQUAL" DATA {parameters.push_back({$2, $4});}
      | PARAMS BOOLEAN_PARAM {parameters.push_back({$2, "true"});}
      | PARAM "tk_EQUAL" DATA {parameters.clear(); parameters.push_back({$1, $3});}
      | BOOLEAN_PARAM {parameters.clear(); parameters.push_back({$1, "true"});}
;

PARAM: "_SIZE" {$$ = "__SIZE";}
      | "_FIT" {$$ = "__FIT";}
      | "_UNIT" {$$ = "__UNIT";}
      | "_PATH" {$$ = "__PATH";}
      | "_TYPE" {$$ = "__TYPE";}
      | "_TYPE2" {$$ = "__TYPE2";}
      | "_DELETE" {$$ = "__DELETE";}
      | "_NAME" {$$ = "__NAME";}
      | "_ADD" {$$ = "__ADD";}
      | "_ID" {$$ = "__ID";}
      | "_FS" {$$ = "__FS";}
      | "_RUTA" {$$ = "__RUTA";}
      | "_USER" {$$ = "__USER";}
      | "_PWD" {$$ = "__PWD";}
      | "_GRP" {$$ = "__GRP";}
      | "_UGO" {$$ = "__UGO";}
      | "_CONT" {$$ = "__CONT";}
      | "_FILEN" {$$ = "__FILEN";}
      | "_DEST" {$$ = "__DEST";}
;

BOOLEAN_PARAM: "_R" {$$ = "__R";}
            | "_P" {$$ = "__R";}
            | "_STDIN" {$$ = "__STDIN";}
;

%%
void yy::class_parser::error(const location_type& lugar, const std::string& lexema)
{
  std::cout << "ERROR SINTÁCTICO: " << lexema << std::endl;
  exit(EXIT_FAILURE);
}
