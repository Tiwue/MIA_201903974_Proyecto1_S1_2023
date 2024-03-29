// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 11 "parser.yy"

#include <string>
#include <stdio.h>

class parser_driver;

#line 55 "parser.tab.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 6 "parser.yy"
namespace yy {
#line 190 "parser.tab.hh"




  /// A Bison parser.
  class class_parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // "tk_EQUAL"
      // "_FIT"
      // "_UNIT"
      // "_PATH"
      // "_SIZE"
      // "_TYPE"
      // "_TYPE2"
      // "_DELETE"
      // "_NAME"
      // "_ADD"
      // "_ID"
      // "_FS"
      // "_login"
      // "_logout"
      // "_MKGRP"
      // "_RMGRP"
      // "_MKUSR"
      // "_RMUSR"
      // "_CHGRP"
      // "_USER"
      // "_PWD"
      // "_GRP"
      // "_MKFILE"
      // "_CHOWN"
      // "_CHMOD"
      // "_CAT"
      // "_RM"
      // "_EDIT"
      // "_REN"
      // "_MV"
      // "_CP"
      // "_MKDIR"
      // "_FIND"
      // "_LOSS"
      // "_RECOVERY"
      // "_R"
      // "_FILEN"
      // "_DEST"
      // "_P"
      // "_CONT"
      // "_UGO"
      // "_STDIN"
      // "_RUTA"
      // "_MKDISK"
      // "_RMDISK"
      // "_FDISK"
      // "_MOUNT"
      // "_UMOUNT"
      // "_MKFS"
      // "tk_string_d"
      // "tk_string_s"
      // "tk_path"
      // "_exec"
      // "_rep"
      // "tk_identifier"
      // "tk_pattern"
      // "tk_number"
      // STRING
      // DATA
      // PARAM
      // BOOLEAN_PARAM
      char dummy1[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_FIN = 0,
        TOK_EQUAL = 258,
        TOK_FIT = 259,
        TOK_UNIT = 260,
        TOK_PATH = 261,
        TOK_SIZE = 262,
        TOK_TYPE = 263,
        TOK_TYPE2 = 264,
        TOK_DELETE = 265,
        TOK_NAME = 266,
        TOK_ADD = 267,
        TOK_ID = 268,
        TOK_FS = 269,
        TOK_LOGIN = 270,
        TOK_LOGOUT = 271,
        TOK_MKGRP = 272,
        TOK_RMGRP = 273,
        TOK_MKUSR = 274,
        TOK_RMUSR = 275,
        TOK_CHGRP = 276,
        TOK_USER = 277,
        TOK_PWD = 278,
        TOK_GRP = 279,
        TOK_MKFILE = 280,
        TOK_CHOWN = 281,
        TOK_CHMOD = 282,
        TOK_CAT = 283,
        TOK_RM = 284,
        TOK_EDIT = 285,
        TOK_REN = 286,
        TOK_MV = 287,
        TOK_CP = 288,
        TOK_MKDIR = 289,
        TOK_FIND = 290,
        TOK_LOSS = 291,
        TOK_RECOVERY = 292,
        TOK_R = 293,
        TOK_FILEN = 294,
        TOK_DEST = 295,
        TOK_P = 296,
        TOK_CONT = 297,
        TOK_UGO = 298,
        TOK_STDIN = 299,
        TOK_RUTA = 300,
        TOK_MKDISK = 301,
        TOK_RMDISK = 302,
        TOK_FDISK = 303,
        TOK_MOUNT = 304,
        TOK_UMOUNT = 305,
        TOK_MKFS = 306,
        TOK_STRING_DOUBLE = 307,
        TOK_STRING_SINGLE = 308,
        TOK_PATH_DIR = 309,
        TOK_RUN_EXEC = 310,
        TOK_RUN_REPORT = 311,
        TOK_IDENTIFICADOR = 312,
        TOK_PATTERN = 313,
        TOK_NUMERO = 314
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_FIN);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::TOK_FIN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_EQUAL || tok == token::TOK_FIT || tok == token::TOK_UNIT || tok == token::TOK_PATH || tok == token::TOK_SIZE || tok == token::TOK_TYPE || tok == token::TOK_TYPE2 || tok == token::TOK_DELETE || tok == token::TOK_NAME || tok == token::TOK_ADD || tok == token::TOK_ID || tok == token::TOK_FS || tok == token::TOK_LOGIN || tok == token::TOK_LOGOUT || tok == token::TOK_MKGRP || tok == token::TOK_RMGRP || tok == token::TOK_MKUSR || tok == token::TOK_RMUSR || tok == token::TOK_CHGRP || tok == token::TOK_USER || tok == token::TOK_PWD || tok == token::TOK_GRP || tok == token::TOK_MKFILE || tok == token::TOK_CHOWN || tok == token::TOK_CHMOD || tok == token::TOK_CAT || tok == token::TOK_RM || tok == token::TOK_EDIT || tok == token::TOK_REN || tok == token::TOK_MV || tok == token::TOK_CP || tok == token::TOK_MKDIR || tok == token::TOK_FIND || tok == token::TOK_LOSS || tok == token::TOK_RECOVERY || tok == token::TOK_R || tok == token::TOK_FILEN || tok == token::TOK_DEST || tok == token::TOK_P || tok == token::TOK_CONT || tok == token::TOK_UGO || tok == token::TOK_STDIN || tok == token::TOK_RUTA || tok == token::TOK_MKDISK || tok == token::TOK_RMDISK || tok == token::TOK_FDISK || tok == token::TOK_MOUNT || tok == token::TOK_UMOUNT || tok == token::TOK_MKFS || tok == token::TOK_STRING_DOUBLE || tok == token::TOK_STRING_SINGLE || tok == token::TOK_PATH_DIR || tok == token::TOK_RUN_EXEC || tok == token::TOK_RUN_REPORT || tok == token::TOK_IDENTIFICADOR || tok == token::TOK_PATTERN || tok == token::TOK_NUMERO);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_EQUAL || tok == token::TOK_FIT || tok == token::TOK_UNIT || tok == token::TOK_PATH || tok == token::TOK_SIZE || tok == token::TOK_TYPE || tok == token::TOK_TYPE2 || tok == token::TOK_DELETE || tok == token::TOK_NAME || tok == token::TOK_ADD || tok == token::TOK_ID || tok == token::TOK_FS || tok == token::TOK_LOGIN || tok == token::TOK_LOGOUT || tok == token::TOK_MKGRP || tok == token::TOK_RMGRP || tok == token::TOK_MKUSR || tok == token::TOK_RMUSR || tok == token::TOK_CHGRP || tok == token::TOK_USER || tok == token::TOK_PWD || tok == token::TOK_GRP || tok == token::TOK_MKFILE || tok == token::TOK_CHOWN || tok == token::TOK_CHMOD || tok == token::TOK_CAT || tok == token::TOK_RM || tok == token::TOK_EDIT || tok == token::TOK_REN || tok == token::TOK_MV || tok == token::TOK_CP || tok == token::TOK_MKDIR || tok == token::TOK_FIND || tok == token::TOK_LOSS || tok == token::TOK_RECOVERY || tok == token::TOK_R || tok == token::TOK_FILEN || tok == token::TOK_DEST || tok == token::TOK_P || tok == token::TOK_CONT || tok == token::TOK_UGO || tok == token::TOK_STDIN || tok == token::TOK_RUTA || tok == token::TOK_MKDISK || tok == token::TOK_RMDISK || tok == token::TOK_FDISK || tok == token::TOK_MOUNT || tok == token::TOK_UMOUNT || tok == token::TOK_MKFS || tok == token::TOK_STRING_DOUBLE || tok == token::TOK_STRING_SINGLE || tok == token::TOK_PATH_DIR || tok == token::TOK_RUN_EXEC || tok == token::TOK_RUN_REPORT || tok == token::TOK_IDENTIFICADOR || tok == token::TOK_PATTERN || tok == token::TOK_NUMERO);
      }
#endif
    };

    /// Build a parser object.
    class_parser (parser_driver& driver_yyarg);
    virtual ~class_parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIN (location_type l)
      {
        return symbol_type (token::TOK_FIN, std::move (l));
      }
#else
      static
      symbol_type
      make_FIN (const location_type& l)
      {
        return symbol_type (token::TOK_FIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (std::string v, location_type l)
      {
        return symbol_type (token::TOK_EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FIT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNIT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_UNIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UNIT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_UNIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PATH (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PATH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PATH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PATH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_SIZE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SIZE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_SIZE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_TYPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_TYPE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE2 (std::string v, location_type l)
      {
        return symbol_type (token::TOK_TYPE2, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE2 (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_TYPE2, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DELETE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DELETE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DELETE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DELETE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAME (std::string v, location_type l)
      {
        return symbol_type (token::TOK_NAME, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NAME (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_NAME, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ADD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ADD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ADD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FS (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGIN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LOGIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOGIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LOGIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGOUT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LOGOUT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOGOUT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LOGOUT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKGRP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKGRP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKGRP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKGRP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMGRP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RMGRP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMGRP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RMGRP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKUSR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKUSR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKUSR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKUSR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMUSR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RMUSR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMUSR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RMUSR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHGRP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CHGRP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHGRP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CHGRP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USER (std::string v, location_type l)
      {
        return symbol_type (token::TOK_USER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_USER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_USER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PWD (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PWD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PWD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PWD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GRP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_GRP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GRP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_GRP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKFILE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKFILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKFILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKFILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHOWN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CHOWN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHOWN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CHOWN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHMOD (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CHMOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHMOD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CHMOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RM (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EDIT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_EDIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EDIT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_EDIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_REN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_REN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MV (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MV, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MV (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MV, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKDIR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKDIR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKDIR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKDIR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIND (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FIND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FIND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FIND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOSS (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LOSS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOSS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LOSS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RECOVERY (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RECOVERY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RECOVERY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RECOVERY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_R (std::string v, location_type l)
      {
        return symbol_type (token::TOK_R, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_R (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_R, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FILEN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FILEN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FILEN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FILEN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEST (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DEST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DEST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DEST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_P (std::string v, location_type l)
      {
        return symbol_type (token::TOK_P, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_P (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_P, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CONT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CONT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UGO (std::string v, location_type l)
      {
        return symbol_type (token::TOK_UGO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UGO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_UGO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STDIN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STDIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STDIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STDIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RUTA (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RUTA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RUTA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RUTA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKDISK (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKDISK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKDISK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKDISK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMDISK (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RMDISK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMDISK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RMDISK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FDISK (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FDISK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FDISK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FDISK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOUNT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MOUNT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MOUNT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MOUNT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMOUNT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_UMOUNT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UMOUNT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_UMOUNT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKFS (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKFS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKFS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKFS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_DOUBLE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STRING_DOUBLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_DOUBLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRING_DOUBLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_SINGLE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STRING_SINGLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_SINGLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRING_SINGLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PATH_DIR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PATH_DIR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PATH_DIR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PATH_DIR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RUN_EXEC (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RUN_EXEC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RUN_EXEC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RUN_EXEC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RUN_REPORT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RUN_REPORT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RUN_REPORT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RUN_REPORT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFICADOR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_IDENTIFICADOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFICADOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_IDENTIFICADOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PATTERN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PATTERN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PATTERN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PATTERN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMERO (std::string v, location_type l)
      {
        return symbol_type (token::TOK_NUMERO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMERO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_NUMERO, v, l);
      }
#endif


  private:
    /// This class is not copyable.
    class_parser (const class_parser&);
    class_parser& operator= (const class_parser&);

    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 101,     ///< Last index in yytable_.
      yynnts_ = 13,  ///< Number of nonterminal symbols.
      yyfinal_ = 64, ///< Termination state number.
      yyntokens_ = 60  ///< Number of tokens.
    };


    // User arguments.
    parser_driver& driver;
  };

  inline
  class_parser::token_number_type
  class_parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
    };
    const int user_token_number_max_ = 314;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  class_parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  class_parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  class_parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  class_parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  class_parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  class_parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  class_parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  class_parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  class_parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  class_parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  class_parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

#line 6 "parser.yy"
} // yy
#line 2384 "parser.tab.hh"





#endif // !YY_YY_PARSER_TAB_HH_INCLUDED
