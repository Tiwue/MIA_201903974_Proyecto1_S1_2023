// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 24 "parser.yy"

#include "driver.h"
#include "../Utils/Builder.h"
#include "../Utils/CommandHandler.cpp"
#include <iostream>
#include <vector>

std::vector<parameter> parameters;
struct command x;


#line 57 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "parser.yy"
namespace yy {
#line 149 "parser.tab.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  class_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  class_parser::class_parser (parser_driver& driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  class_parser::~class_parser ()
  {}

  class_parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  class_parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  class_parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  class_parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  class_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  class_parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  class_parser::symbol_number_type
  class_parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  class_parser::stack_symbol_type::stack_symbol_type ()
  {}

  class_parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 3: // "tk_EQUAL"
      case 4: // "_FIT"
      case 5: // "_UNIT"
      case 6: // "_PATH"
      case 7: // "_SIZE"
      case 8: // "_TYPE"
      case 9: // "_TYPE2"
      case 10: // "_DELETE"
      case 11: // "_NAME"
      case 12: // "_ADD"
      case 13: // "_ID"
      case 14: // "_FS"
      case 15: // "_login"
      case 16: // "_logout"
      case 17: // "_MKGRP"
      case 18: // "_RMGRP"
      case 19: // "_MKUSR"
      case 20: // "_RMUSR"
      case 21: // "_CHGRP"
      case 22: // "_USER"
      case 23: // "_PWD"
      case 24: // "_GRP"
      case 25: // "_MKFILE"
      case 26: // "_CHOWN"
      case 27: // "_CHMOD"
      case 28: // "_CAT"
      case 29: // "_RM"
      case 30: // "_EDIT"
      case 31: // "_REN"
      case 32: // "_MV"
      case 33: // "_CP"
      case 34: // "_MKDIR"
      case 35: // "_FIND"
      case 36: // "_LOSS"
      case 37: // "_RECOVERY"
      case 38: // "_R"
      case 39: // "_FILEN"
      case 40: // "_DEST"
      case 41: // "_P"
      case 42: // "_CONT"
      case 43: // "_UGO"
      case 44: // "_STDIN"
      case 45: // "_RUTA"
      case 46: // "_MKDISK"
      case 47: // "_RMDISK"
      case 48: // "_FDISK"
      case 49: // "_MOUNT"
      case 50: // "_UMOUNT"
      case 51: // "_MKFS"
      case 52: // "tk_string_d"
      case 53: // "tk_string_s"
      case 54: // "tk_path"
      case 55: // "_exec"
      case 56: // "_rep"
      case 57: // "tk_identifier"
      case 58: // "tk_pattern"
      case 59: // "tk_number"
      case 62: // STRING
      case 63: // DATA
      case 71: // PARAM
      case 72: // BOOLEAN_PARAM
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  class_parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 3: // "tk_EQUAL"
      case 4: // "_FIT"
      case 5: // "_UNIT"
      case 6: // "_PATH"
      case 7: // "_SIZE"
      case 8: // "_TYPE"
      case 9: // "_TYPE2"
      case 10: // "_DELETE"
      case 11: // "_NAME"
      case 12: // "_ADD"
      case 13: // "_ID"
      case 14: // "_FS"
      case 15: // "_login"
      case 16: // "_logout"
      case 17: // "_MKGRP"
      case 18: // "_RMGRP"
      case 19: // "_MKUSR"
      case 20: // "_RMUSR"
      case 21: // "_CHGRP"
      case 22: // "_USER"
      case 23: // "_PWD"
      case 24: // "_GRP"
      case 25: // "_MKFILE"
      case 26: // "_CHOWN"
      case 27: // "_CHMOD"
      case 28: // "_CAT"
      case 29: // "_RM"
      case 30: // "_EDIT"
      case 31: // "_REN"
      case 32: // "_MV"
      case 33: // "_CP"
      case 34: // "_MKDIR"
      case 35: // "_FIND"
      case 36: // "_LOSS"
      case 37: // "_RECOVERY"
      case 38: // "_R"
      case 39: // "_FILEN"
      case 40: // "_DEST"
      case 41: // "_P"
      case 42: // "_CONT"
      case 43: // "_UGO"
      case 44: // "_STDIN"
      case 45: // "_RUTA"
      case 46: // "_MKDISK"
      case 47: // "_RMDISK"
      case 48: // "_FDISK"
      case 49: // "_MOUNT"
      case 50: // "_UMOUNT"
      case 51: // "_MKFS"
      case 52: // "tk_string_d"
      case 53: // "tk_string_s"
      case 54: // "tk_path"
      case 55: // "_exec"
      case 56: // "_rep"
      case 57: // "tk_identifier"
      case 58: // "tk_pattern"
      case 59: // "tk_number"
      case 62: // STRING
      case 63: // DATA
      case 71: // PARAM
      case 72: // BOOLEAN_PARAM
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  class_parser::stack_symbol_type&
  class_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // "tk_EQUAL"
      case 4: // "_FIT"
      case 5: // "_UNIT"
      case 6: // "_PATH"
      case 7: // "_SIZE"
      case 8: // "_TYPE"
      case 9: // "_TYPE2"
      case 10: // "_DELETE"
      case 11: // "_NAME"
      case 12: // "_ADD"
      case 13: // "_ID"
      case 14: // "_FS"
      case 15: // "_login"
      case 16: // "_logout"
      case 17: // "_MKGRP"
      case 18: // "_RMGRP"
      case 19: // "_MKUSR"
      case 20: // "_RMUSR"
      case 21: // "_CHGRP"
      case 22: // "_USER"
      case 23: // "_PWD"
      case 24: // "_GRP"
      case 25: // "_MKFILE"
      case 26: // "_CHOWN"
      case 27: // "_CHMOD"
      case 28: // "_CAT"
      case 29: // "_RM"
      case 30: // "_EDIT"
      case 31: // "_REN"
      case 32: // "_MV"
      case 33: // "_CP"
      case 34: // "_MKDIR"
      case 35: // "_FIND"
      case 36: // "_LOSS"
      case 37: // "_RECOVERY"
      case 38: // "_R"
      case 39: // "_FILEN"
      case 40: // "_DEST"
      case 41: // "_P"
      case 42: // "_CONT"
      case 43: // "_UGO"
      case 44: // "_STDIN"
      case 45: // "_RUTA"
      case 46: // "_MKDISK"
      case 47: // "_RMDISK"
      case 48: // "_FDISK"
      case 49: // "_MOUNT"
      case 50: // "_UMOUNT"
      case 51: // "_MKFS"
      case 52: // "tk_string_d"
      case 53: // "tk_string_s"
      case 54: // "tk_path"
      case 55: // "_exec"
      case 56: // "_rep"
      case 57: // "tk_identifier"
      case 58: // "tk_pattern"
      case 59: // "tk_number"
      case 62: // STRING
      case 63: // DATA
      case 71: // PARAM
      case 72: // BOOLEAN_PARAM
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  class_parser::stack_symbol_type&
  class_parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // "tk_EQUAL"
      case 4: // "_FIT"
      case 5: // "_UNIT"
      case 6: // "_PATH"
      case 7: // "_SIZE"
      case 8: // "_TYPE"
      case 9: // "_TYPE2"
      case 10: // "_DELETE"
      case 11: // "_NAME"
      case 12: // "_ADD"
      case 13: // "_ID"
      case 14: // "_FS"
      case 15: // "_login"
      case 16: // "_logout"
      case 17: // "_MKGRP"
      case 18: // "_RMGRP"
      case 19: // "_MKUSR"
      case 20: // "_RMUSR"
      case 21: // "_CHGRP"
      case 22: // "_USER"
      case 23: // "_PWD"
      case 24: // "_GRP"
      case 25: // "_MKFILE"
      case 26: // "_CHOWN"
      case 27: // "_CHMOD"
      case 28: // "_CAT"
      case 29: // "_RM"
      case 30: // "_EDIT"
      case 31: // "_REN"
      case 32: // "_MV"
      case 33: // "_CP"
      case 34: // "_MKDIR"
      case 35: // "_FIND"
      case 36: // "_LOSS"
      case 37: // "_RECOVERY"
      case 38: // "_R"
      case 39: // "_FILEN"
      case 40: // "_DEST"
      case 41: // "_P"
      case 42: // "_CONT"
      case 43: // "_UGO"
      case 44: // "_STDIN"
      case 45: // "_RUTA"
      case 46: // "_MKDISK"
      case 47: // "_RMDISK"
      case 48: // "_FDISK"
      case 49: // "_MOUNT"
      case 50: // "_UMOUNT"
      case 51: // "_MKFS"
      case 52: // "tk_string_d"
      case 53: // "tk_string_s"
      case 54: // "tk_path"
      case 55: // "_exec"
      case 56: // "_rep"
      case 57: // "tk_identifier"
      case 58: // "tk_pattern"
      case 59: // "tk_number"
      case 62: // STRING
      case 63: // DATA
      case 71: // PARAM
      case 72: // BOOLEAN_PARAM
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  class_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  class_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  class_parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  class_parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  class_parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  class_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  class_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  class_parser::debug_level_type
  class_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  class_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  class_parser::state_type
  class_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  class_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  class_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  class_parser::operator() ()
  {
    return parse ();
  }

  int
  class_parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 3: // "tk_EQUAL"
      case 4: // "_FIT"
      case 5: // "_UNIT"
      case 6: // "_PATH"
      case 7: // "_SIZE"
      case 8: // "_TYPE"
      case 9: // "_TYPE2"
      case 10: // "_DELETE"
      case 11: // "_NAME"
      case 12: // "_ADD"
      case 13: // "_ID"
      case 14: // "_FS"
      case 15: // "_login"
      case 16: // "_logout"
      case 17: // "_MKGRP"
      case 18: // "_RMGRP"
      case 19: // "_MKUSR"
      case 20: // "_RMUSR"
      case 21: // "_CHGRP"
      case 22: // "_USER"
      case 23: // "_PWD"
      case 24: // "_GRP"
      case 25: // "_MKFILE"
      case 26: // "_CHOWN"
      case 27: // "_CHMOD"
      case 28: // "_CAT"
      case 29: // "_RM"
      case 30: // "_EDIT"
      case 31: // "_REN"
      case 32: // "_MV"
      case 33: // "_CP"
      case 34: // "_MKDIR"
      case 35: // "_FIND"
      case 36: // "_LOSS"
      case 37: // "_RECOVERY"
      case 38: // "_R"
      case 39: // "_FILEN"
      case 40: // "_DEST"
      case 41: // "_P"
      case 42: // "_CONT"
      case 43: // "_UGO"
      case 44: // "_STDIN"
      case 45: // "_RUTA"
      case 46: // "_MKDISK"
      case 47: // "_RMDISK"
      case 48: // "_FDISK"
      case 49: // "_MOUNT"
      case 50: // "_UMOUNT"
      case 51: // "_MKFS"
      case 52: // "tk_string_d"
      case 53: // "tk_string_s"
      case 54: // "tk_path"
      case 55: // "_exec"
      case 56: // "_rep"
      case 57: // "tk_identifier"
      case 58: // "tk_pattern"
      case 59: // "tk_number"
      case 62: // STRING
      case 63: // DATA
      case 71: // PARAM
      case 72: // BOOLEAN_PARAM
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 122 "parser.yy"
                  {return CommandHandler(x);}
#line 896 "parser.tab.cc"
    break;

  case 4:
#line 126 "parser.yy"
                      {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ().substr(1, yystack_[0].value.as < std::string > ().size() - 2);}
#line 902 "parser.tab.cc"
    break;

  case 5:
#line 127 "parser.yy"
                      {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ().substr(1, yystack_[0].value.as < std::string > ().size() - 2);}
#line 908 "parser.tab.cc"
    break;

  case 6:
#line 130 "parser.yy"
             {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 914 "parser.tab.cc"
    break;

  case 7:
#line 131 "parser.yy"
                  {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 920 "parser.tab.cc"
    break;

  case 8:
#line 132 "parser.yy"
                {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 926 "parser.tab.cc"
    break;

  case 9:
#line 133 "parser.yy"
                      {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 932 "parser.tab.cc"
    break;

  case 10:
#line 134 "parser.yy"
                   {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 938 "parser.tab.cc"
    break;

  case 16:
#line 145 "parser.yy"
                     {x = newCommand("__EXEC",parameters);}
#line 944 "parser.tab.cc"
    break;

  case 17:
#line 148 "parser.yy"
                         {x = newCommand("__MKDISK",parameters);}
#line 950 "parser.tab.cc"
    break;

  case 18:
#line 149 "parser.yy"
                           {x = newCommand("__RMDISK",parameters);}
#line 956 "parser.tab.cc"
    break;

  case 19:
#line 150 "parser.yy"
                          {x = newCommand("__FDISK",parameters);}
#line 962 "parser.tab.cc"
    break;

  case 20:
#line 151 "parser.yy"
                          {x = newCommand("__MOUNT",parameters);}
#line 968 "parser.tab.cc"
    break;

  case 21:
#line 152 "parser.yy"
                           {x = newCommand("__UMOUNT",parameters);}
#line 974 "parser.tab.cc"
    break;

  case 22:
#line 153 "parser.yy"
                         {x = newCommand("__MKFS",parameters);}
#line 980 "parser.tab.cc"
    break;

  case 23:
#line 154 "parser.yy"
                          {x = newCommand("__MKGRP",parameters);}
#line 986 "parser.tab.cc"
    break;

  case 24:
#line 155 "parser.yy"
                          {x = newCommand("__RMGRP",parameters);}
#line 992 "parser.tab.cc"
    break;

  case 25:
#line 156 "parser.yy"
                          {x = newCommand("__MKUSR",parameters);}
#line 998 "parser.tab.cc"
    break;

  case 26:
#line 157 "parser.yy"
                          {x = newCommand("__RMUSR",parameters);}
#line 1004 "parser.tab.cc"
    break;

  case 27:
#line 160 "parser.yy"
                             {x = newCommand("__MKFILE",parameters);}
#line 1010 "parser.tab.cc"
    break;

  case 28:
#line 161 "parser.yy"
                              {x = newCommand("__MKDIR",parameters);}
#line 1016 "parser.tab.cc"
    break;

  case 29:
#line 165 "parser.yy"
                      {x = newCommand("__REP",parameters);}
#line 1022 "parser.tab.cc"
    break;

  case 30:
#line 168 "parser.yy"
                                     {parameters.push_back({yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()});}
#line 1028 "parser.tab.cc"
    break;

  case 31:
#line 169 "parser.yy"
                             {parameters.push_back({yystack_[0].value.as < std::string > (), "true"});}
#line 1034 "parser.tab.cc"
    break;

  case 32:
#line 170 "parser.yy"
                              {parameters.clear(); parameters.push_back({yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()});}
#line 1040 "parser.tab.cc"
    break;

  case 33:
#line 171 "parser.yy"
                      {parameters.clear(); parameters.push_back({yystack_[0].value.as < std::string > (), "true"});}
#line 1046 "parser.tab.cc"
    break;

  case 34:
#line 174 "parser.yy"
                                    {x = newCommand("__LOGIN",parameters);}
#line 1052 "parser.tab.cc"
    break;

  case 35:
#line 175 "parser.yy"
                              {x = newCommand("__LOGOUT",parameters);}
#line 1058 "parser.tab.cc"
    break;

  case 36:
#line 177 "parser.yy"
               {yylhs.value.as < std::string > () = "__SIZE";}
#line 1064 "parser.tab.cc"
    break;

  case 37:
#line 178 "parser.yy"
               {yylhs.value.as < std::string > () = "__FIT";}
#line 1070 "parser.tab.cc"
    break;

  case 38:
#line 179 "parser.yy"
                {yylhs.value.as < std::string > () = "__UNIT";}
#line 1076 "parser.tab.cc"
    break;

  case 39:
#line 180 "parser.yy"
                {yylhs.value.as < std::string > () = "__PATH";}
#line 1082 "parser.tab.cc"
    break;

  case 40:
#line 181 "parser.yy"
                {yylhs.value.as < std::string > () = "__TYPE";}
#line 1088 "parser.tab.cc"
    break;

  case 41:
#line 182 "parser.yy"
                 {yylhs.value.as < std::string > () = "__TYPE2";}
#line 1094 "parser.tab.cc"
    break;

  case 42:
#line 183 "parser.yy"
                  {yylhs.value.as < std::string > () = "__DELETE";}
#line 1100 "parser.tab.cc"
    break;

  case 43:
#line 184 "parser.yy"
                {yylhs.value.as < std::string > () = "__NAME";}
#line 1106 "parser.tab.cc"
    break;

  case 44:
#line 185 "parser.yy"
               {yylhs.value.as < std::string > () = "__ADD";}
#line 1112 "parser.tab.cc"
    break;

  case 45:
#line 186 "parser.yy"
              {yylhs.value.as < std::string > () = "__ID";}
#line 1118 "parser.tab.cc"
    break;

  case 46:
#line 187 "parser.yy"
              {yylhs.value.as < std::string > () = "__FS";}
#line 1124 "parser.tab.cc"
    break;

  case 47:
#line 188 "parser.yy"
                {yylhs.value.as < std::string > () = "__RUTA";}
#line 1130 "parser.tab.cc"
    break;

  case 48:
#line 189 "parser.yy"
                {yylhs.value.as < std::string > () = "__USER";}
#line 1136 "parser.tab.cc"
    break;

  case 49:
#line 190 "parser.yy"
               {yylhs.value.as < std::string > () = "__PWD";}
#line 1142 "parser.tab.cc"
    break;

  case 50:
#line 191 "parser.yy"
               {yylhs.value.as < std::string > () = "__GRP";}
#line 1148 "parser.tab.cc"
    break;

  case 51:
#line 192 "parser.yy"
               {yylhs.value.as < std::string > () = "__UGO";}
#line 1154 "parser.tab.cc"
    break;

  case 52:
#line 193 "parser.yy"
                {yylhs.value.as < std::string > () = "__CONT";}
#line 1160 "parser.tab.cc"
    break;

  case 53:
#line 194 "parser.yy"
                 {yylhs.value.as < std::string > () = "__FILEN";}
#line 1166 "parser.tab.cc"
    break;

  case 54:
#line 195 "parser.yy"
                {yylhs.value.as < std::string > () = "__DEST";}
#line 1172 "parser.tab.cc"
    break;

  case 55:
#line 198 "parser.yy"
                    {yylhs.value.as < std::string > () = "__R";}
#line 1178 "parser.tab.cc"
    break;

  case 56:
#line 199 "parser.yy"
                   {yylhs.value.as < std::string > () = "__R";}
#line 1184 "parser.tab.cc"
    break;

  case 57:
#line 200 "parser.yy"
                       {yylhs.value.as < std::string > () = "__STDIN";}
#line 1190 "parser.tab.cc"
    break;


#line 1194 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  class_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  class_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char class_parser::yypact_ninf_ = -41;

  const signed char class_parser::yytable_ninf_ = -1;

  const signed char
  class_parser::yypact_[] =
  {
       0,   -41,    -1,   -41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,     2,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,    -1,    11,   -41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   -41,   -41,    21,   -41,   -26,   -26,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41
  };

  const signed char
  class_parser::yydefact_[] =
  {
       0,     3,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    15,    13,    14,    37,    38,    39,    36,    40,
      41,    42,    43,    44,    45,    46,    48,    49,    50,    55,
      53,    54,    56,    52,    51,    57,    47,    34,     0,    33,
      23,    24,    25,    26,    27,    28,    17,    18,    19,    20,
      21,    22,    16,    29,     1,     2,     0,    31,     0,     0,
       4,     5,     8,     9,    10,     7,     6,    32,    30
  };

  const signed char
  class_parser::yypgoto_[] =
  {
     -41,   -41,   -41,   -40,   -41,   -41,   -41,   -41,   -41,    84,
     -41,     7,    24
  };

  const signed char
  class_parser::yydefgoto_[] =
  {
      -1,    18,    76,    77,    19,    20,    21,    22,    23,    47,
      24,    48,    49
  };

  const signed char
  class_parser::yytable_[] =
  {
       1,    64,    65,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    68,     2,     3,     4,     5,     6,
       7,    36,    37,    38,    69,     8,    70,    71,    72,    78,
       0,    73,    74,    75,     9,     0,     0,    39,    40,    41,
      42,    43,    44,    45,    46,     0,    10,    11,    12,    13,
      14,    15,     0,     0,    66,    16,    17,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,     0,     0,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63
  };

  const signed char
  class_parser::yycheck_[] =
  {
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     3,    15,    16,    17,    18,    19,
      20,    22,    23,    24,     3,    25,    52,    53,    54,    69,
      -1,    57,    58,    59,    34,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    46,    47,    48,    49,
      50,    51,    -1,    -1,    47,    55,    56,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    47,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17
  };

  const signed char
  class_parser::yystos_[] =
  {
       0,     0,    15,    16,    17,    18,    19,    20,    25,    34,
      46,    47,    48,    49,    50,    51,    55,    56,    61,    64,
      65,    66,    67,    68,    70,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    22,    23,    24,    38,
      39,    40,    41,    42,    43,    44,    45,    69,    71,    72,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,     0,     0,    71,    72,     3,     3,
      52,    53,    54,    57,    58,    59,    62,    63,    63
  };

  const signed char
  class_parser::yyr1_[] =
  {
       0,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      69,    69,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    72
  };

  const signed char
  class_parser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     2,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const class_parser::yytname_[] =
  {
  "\"eof\"", "error", "$undefined", "\"tk_EQUAL\"", "\"_FIT\"",
  "\"_UNIT\"", "\"_PATH\"", "\"_SIZE\"", "\"_TYPE\"", "\"_TYPE2\"",
  "\"_DELETE\"", "\"_NAME\"", "\"_ADD\"", "\"_ID\"", "\"_FS\"",
  "\"_login\"", "\"_logout\"", "\"_MKGRP\"", "\"_RMGRP\"", "\"_MKUSR\"",
  "\"_RMUSR\"", "\"_CHGRP\"", "\"_USER\"", "\"_PWD\"", "\"_GRP\"",
  "\"_MKFILE\"", "\"_CHOWN\"", "\"_CHMOD\"", "\"_CAT\"", "\"_RM\"",
  "\"_EDIT\"", "\"_REN\"", "\"_MV\"", "\"_CP\"", "\"_MKDIR\"", "\"_FIND\"",
  "\"_LOSS\"", "\"_RECOVERY\"", "\"_R\"", "\"_FILEN\"", "\"_DEST\"",
  "\"_P\"", "\"_CONT\"", "\"_UGO\"", "\"_STDIN\"", "\"_RUTA\"",
  "\"_MKDISK\"", "\"_RMDISK\"", "\"_FDISK\"", "\"_MOUNT\"", "\"_UMOUNT\"",
  "\"_MKFS\"", "\"tk_string_d\"", "\"tk_string_s\"", "\"tk_path\"",
  "\"_exec\"", "\"_rep\"", "\"tk_identifier\"", "\"tk_pattern\"",
  "\"tk_number\"", "$accept", "INICIO", "STRING", "DATA", "E", "EXEC",
  "DISCOS", "FILESYSTEM", "REPORT", "PARAMS", "ADMIN_USERS_GROUPS",
  "PARAM", "BOOLEAN_PARAM", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  class_parser::yyrline_[] =
  {
       0,   122,   122,   123,   126,   127,   130,   131,   132,   133,
     134,   137,   138,   139,   140,   141,   145,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   160,   161,   165,
     168,   169,   170,   171,   174,   175,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   198,   199,   200
  };

  // Print the state stack on the debug stream.
  void
  class_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  class_parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 6 "parser.yy"
} // yy
#line 1644 "parser.tab.cc"

#line 203 "parser.yy"

void yy::class_parser::error(const location_type& lugar, const std::string& lexema)
{
  std::cout << "ERROR SINTÁCTICO: " << lexema << std::endl;
  exit(EXIT_FAILURE);
}
