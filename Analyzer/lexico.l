%{
#include <cerrno>
#include <stdio.h>
#include <string>
#include "driver.h"
#include "parser.tab.hh"
#undef yywrap
#define yywrap() 1
static yy::location loc;
%}

%option noyywrap nounput batch debug noinput
%option case-insensitive
%option outfile="scanner.cpp"

COMENTARIOS "#".*
GUION ">"
STRING_DOUBLE \"(\\.|[^"\\])*\"
STRING_SINGLE \'(\\.|[^"\\])*\'
SPACE " "+
DIGITO [0-9]
LETRA [a-zA-ZñÑ]
PATTERN [*?]"."{LETRA}+
NUMERO "-"?{DIGITO}+("."{DIGITO}+)?
IDENTIFICADOR ({LETRA}|{DIGITO}|"_")+
DELIMITADOR [\t\r\n\f]
PATH_DIR \/.[^" "]+|{IDENTIFICADOR}"."{IDENTIFICADOR}

%%

"="		                  {return yy::class_parser::make_EQUAL(yytext, loc);}
{GUION}"fit"		          {return yy::class_parser::make_FIT(yytext, loc);}
{GUION}"unit"		   {return yy::class_parser::make_UNIT(yytext, loc);}
{GUION}"path"          {return yy::class_parser::make_PATH(yytext, loc);}
{GUION}"size"          {return yy::class_parser::make_SIZE(yytext, loc);}
{GUION}"t"             {return yy::class_parser::make_TYPE(yytext, loc);}
{GUION}"type"          {return yy::class_parser::make_TYPE2(yytext, loc);}
{GUION}"delete"        {return yy::class_parser::make_DELETE(yytext, loc);}
{GUION}"name"          {return yy::class_parser::make_NAME(yytext, loc);}
{GUION}"add"           {return yy::class_parser::make_ADD(yytext, loc);}
{GUION}"id"            {return yy::class_parser::make_ID(yytext, loc);}
{GUION}"fs"            {return yy::class_parser::make_FS(yytext, loc);}

{GUION}"ruta"          {return yy::class_parser::make_RUTA(yytext, loc);}



"mkdisk"		            {return yy::class_parser::make_MKDISK(yytext, loc);}
"rmdisk"		            {return yy::class_parser::make_RMDISK(yytext, loc);}
"fdisk"		              {return yy::class_parser::make_FDISK(yytext, loc);}
"mount"		              {return yy::class_parser::make_MOUNT(yytext, loc);}
"umount"		            {return yy::class_parser::make_UMOUNT(yytext, loc);}
"mkfs"		              {return yy::class_parser::make_MKFS(yytext, loc);}
"exec"		              {return yy::class_parser::make_RUN_EXEC(yytext, loc);}
"rep"                   {return yy::class_parser::make_RUN_REPORT(yytext, loc);}

"login"                 {return yy::class_parser::make_LOGIN(yytext, loc);}
"logout"                {return yy::class_parser::make_LOGOUT(yytext, loc);}
"mkgrp"                 {return yy::class_parser::make_MKGRP(yytext, loc);}
"rmgrp"                 {return yy::class_parser::make_RMGRP(yytext, loc);}
"mkusr"                 {return yy::class_parser::make_MKUSR(yytext, loc);}
"rmusr"                 {return yy::class_parser::make_RMUSR(yytext, loc);}
"chgrp"                 {return yy::class_parser::make_CHGRP(yytext, loc);}
{GUION}("user"|"usr")  {return yy::class_parser::make_USER(yytext, loc);}
{GUION}"pass"           {return yy::class_parser::make_PWD(yytext, loc);}
{GUION}"grp"           {return yy::class_parser::make_GRP(yytext, loc);}

"chmod"                 {return yy::class_parser::make_CHMOD(yytext, loc);}
"chown"                 {return yy::class_parser::make_CHOWN(yytext, loc);}
"mkfile"                 {return yy::class_parser::make_MKFILE(yytext, loc);}
"cat"                   {return yy::class_parser::make_CAT(yytext, loc);}
"rm"                    {return yy::class_parser::make_RM(yytext, loc);}
"edit"                  {return yy::class_parser::make_EDIT(yytext, loc);}
"ren"                   {return yy::class_parser::make_REN(yytext, loc);}
"mv"                    {return yy::class_parser::make_MV(yytext, loc);}
"cp"                    {return yy::class_parser::make_CP(yytext, loc);}
"find"                  {return yy::class_parser::make_FIND(yytext, loc);}
"mkdir"                 {return yy::class_parser::make_MKDIR(yytext, loc);}
"loss"                  {return yy::class_parser::make_LOSS(yytext, loc);}
"recovery"              {return yy::class_parser::make_RECOVERY(yytext, loc);}
{GUION}"ugo"           {return yy::class_parser::make_UGO(yytext, loc);}
{GUION}"cont"          {return yy::class_parser::make_CONT(yytext, loc);}
{GUION}"stdin"         {return yy::class_parser::make_STDIN(yytext, loc);}
{GUION}"r"             {return yy::class_parser::make_R(yytext, loc);}
{GUION}"file"{NUMERO}  {return yy::class_parser::make_FILEN(yytext, loc);}
{GUION}"p"             {return yy::class_parser::make_P(yytext, loc);}
{GUION}"destino"          {return yy::class_parser::make_DEST(yytext, loc);}

"pause"                 {
                          std::cout << "Ingrese cualquier tecla para continuar: ";
                          std::cin.ignore();
                        }
"__quit__"              {exit(1);}

{STRING_DOUBLE}         {return yy::class_parser::make_STRING_DOUBLE(yytext, loc);}
{STRING_SINGLE}         {return yy::class_parser::make_STRING_SINGLE(yytext, loc);}
{PATH_DIR}              {return yy::class_parser::make_PATH_DIR(yytext, loc);}
{NUMERO}                {return yy::class_parser::make_NUMERO(yytext ,loc);}
{IDENTIFICADOR}	        {return yy::class_parser::make_IDENTIFICADOR(yytext, loc);}
{PATTERN}	              {return yy::class_parser::make_PATTERN(yytext, loc);}
{SPACE}                 {}
{DELIMITADOR}           {}
{COMENTARIOS}           {}

.                       {printf("ERROR LEXICO %s\n",yytext);}
<<EOF>>		              {return yy::class_parser::make_FIN(loc);}


%%

void parser_driver::iniciarScanner()
{
  yy_flex_debug = false;
  if(file.empty() || file == "-"){
    printf("No se encuentra el archivo de entrada");
    exit(1);
  }else{
    yyin = fopen (file.c_str (), "r");
  }
}

void parser_driver::terminarScanner()
{
  fclose(yyin);
}