%------------------------------------------------------------------------------

% EM USO NORMAL, ESTE ARQUIVO NÃO DEVE SER MODIFICADO!

% Esta classe define o padrão para dissertações, teses e documentos
% correlatos produzidos no Programa de Pós-Graduação em Informática
% da Universidade Federal do Paraná, em Curitiba PR.
%
% Esta classe segue o modelo da classe "book" e aceita todas as suas opções.
% Ela também define as seguintes opções específicas:
% 
%    defesa: versão prévia (só frente, espaçamento 1.5,)
%    final:  versão final (frente/verso, espaçamento 1, páginas complementares)

% Os seguintes ambientes e comandos também são definidos:
%
% \descr{...}		: descrição do documento na folha de rosto
% \instit{short}{long}	: instituição (abreviado e por extenso)
% \advisor{Nome}	: define o orientador
% \coadvisor{Nome}	: define o coorientador, se houver
% \field{Área}		: define a área de concentração da pesquisa
% \local{Cidade}	: define o local da defesa
% \keywords{}{}...	: define três palavras-chave e três keywords
% \coverimage{}		: define a imagem de fundo da capa
% \begin{resumo}	: define a página de resumo
% \begin{abstract}	: define a página de abstract
% \begin{agradece}	: define a página de agradecimentos
% \begin{dedica}	: define a página de dedicatória
% \begin{ficha}		: define a ficha catalográfica
% \begin{aprovacao}	: define a folha de aprovação
% \source{fonte}	: define fonte de uma figura/tabela
% \note{nota}		: define nota em uma figura/tabela
%
% Software fornecido sob a licença GNU GPL. Pode ser usada e modificada
% livremente, desde que mantidas as informações deste cabeçalho.
%
% Autoria: prof. Carlos A. Maziero, DInf/UFPR (maziero@inf.ufpr.br)

%------------------------------------------------------------------------------

% definição da classe e versão
\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{ppginf}[2026/05/22 Manuscript LaTeX class for PPGInf/UFPR]

%------------------------------------------------------------------------------

% OPÇÕES DESTA CLASSE

% flags de controle
\newif\iffinalmode	% versão final do documento? default false
\finalmodefalse
\newif\ifmetadata	% incluir metadados no PDF? default false
\metadatafalse

% defesa: só frente, espaçamento 1,5 e menos páginas iniciais
\DeclareOption{defesa}{\finalmodefalse}

% aprovada: frente/verso, espaçamento 1 e mais páginas iniciais
\DeclareOption{final}{\finalmodetrue}

% metadados: inclui metadados no PDF
\DeclareOption{metadados}{\metadatatrue}

% demais opções devem ser encaminhadas à classe de base (book)
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{book}}

% processa as opções definidas acima
\ProcessOptions

%------------------------------------------------------------------------------

%% Carregar a classe de base
\iffinalmode
  \if@twoside
    \LoadClass[12pt,a4paper,twoside]{book}	% twoside na final
  \else%
    \LoadClass[12pt,a4paper,oneside]{book}	% oneside na final
  \fi
\else
  \if@twoside
    \LoadClass[12pt,a4paper,twoside]{book}	% twoside na defesa
  \else%
    \LoadClass[12pt,a4paper,oneside]{book}	% oneside na defesa
  \fi
\fi

% ------------------------------------------------------------------------------

% suporte a texto com múltiplas línguas
\usepackage{babel}
\usepackage{iflang}

% nomes dos capítulos/seções/campos/etc em português e inglês
\IfLanguageName{brazilian}
{
  \def\@listabbrevs{LISTA DE ABREVIATURAS E SIGLAS}
  \def\@listsymbols{LISTA DE S\'IMBOLOS}
  \def\@chapthanks{AGRADECIMENTOS}
  \def\@tagappendix{AP\^ENDICE}
  \def\@tagfield{\'Area de concentra\c{c}\~ao}
  \def\@tagadvisor{Orientador}
  \def\@tagcoadvisor{Coorientador}
  \def\@tagnote{Nota}
  \def\@tagsource{Fonte}
}
{
  \def\@listabbrevs{LIST OF ABBREVIATIONS AND ACRONYMS}
  \def\@listsymbols{LIST OF SYMBOLS}
  \def\@chapthanks{ACKNOWLEDGEMENTS}
  \def\@tagappendix{APPENDIX}
% a Bib/UFPR exige que a folha de rosto seja em português, exceto o título :-(
%  \def\@tagfield{Field}
%  \def\@tagadvisor{Advisor}
%  \def\@tagcoadvisor{Co-advisor}
  \def\@tagfield{\'Area de concentra\c{c}\~ao}
  \def\@tagadvisor{Orientador}
  \def\@tagcoadvisor{Coorientador}
  \def\@tagnote{Note}
  \def\@tagsource{Source}
}

%------------------------------------------------------------------------------

% ajustar dimensões da página e margens

\RequirePackage{geometry}
\geometry{a4paper}
\geometry{right=2cm,left=2cm,top=3cm,bottom=2cm}
\geometry{bindingoffset=1cm}

%------------------------------------------------------------------------------

% ajustar formato dos títulos nas seções

\RequirePackage[explicit]{titlesec}

\newcommand{\numberspacing}{1.5ex}	% espaço entre número e título

% capítulo
\titleformat{\chapter}[hang]
  {\normalfont\bfseries}
  {\thechapter}
  {\numberspacing}
  {\MakeUppercase{#1}}

% seção
\titleformat{name=\section}[hang]
  {\normalfont}
  {\thesection}
  {\numberspacing}
  {\MakeUppercase{#1}}

% subseção
\titleformat{name=\subsection}[hang]
  {\normalfont}
  {\thesubsection}
  {\numberspacing}
  {#1}

% subsubseção
\titleformat{name=\subsubsection}[hang]
  {\normalfont\normalsize\itshape}
  {\thesubsubsection}
  {\numberspacing}
  {#1}

% capítulo não numerado
\titleformat{name=\chapter,numberless}[hang]
  {\MakeUppercase\normalfont\bfseries}
  {}
  {0ex}
  {\centering #1}

% seção não numerada
\titleformat{name=\section,numberless}[hang]
  {\normalfont}
  {\thesection}
  {\numberspacing}
  {\MakeUppercase{#1}}

% subseção não numerada
\titleformat{name=\subsection,numberless}[hang]
  {\normalfont}
  {\thesubsection}
  {\numberspacing}
  {#1}

% subsubseção não numerada
\titleformat{name=\subsubsection,numberless}[hang]
  {\normalfont\normalsize\itshape}
  {\thesubsubsection}
  {\numberspacing}
  {#1}

% ajusta alguns espaçamentos
\titlespacing*{name=\chapter}			{0pt}{0pt}{30pt}
\titlespacing*{name=\chapter,numberless}	{0pt}{0pt}{30pt}

% permite subsubsections
\setcounter{secnumdepth}{3}

%------------------------------------------------------------------------------

% ajustar formato das entradas no sumário

\RequirePackage{titletoc}

\newcommand{\leftindent}{15mm}		% endentação das entradas
\newcommand{\dotspacing}{0.75pc}	% espaçamento dos pontinhos

% espaço vertical entre linhas
\iffinalmode
  \newcommand{\linespacing}{0.75ex}
\else
  \newcommand{\linespacing}{0.0ex}
\fi

% capítulo
\titlecontents{chapter}
  [\leftindent]
  {\normalfont\normalsize\bfseries}
  {\contentslabel{\leftindent}\uppercase}
  {}
  {\titlerule*[\dotspacing]{.}\contentspage}
  [\vspace{\linespacing}]

% seção
\titlecontents{section}
  [\leftindent]
  {\normalfont\normalsize}
  {\contentslabel{\leftindent}\uppercase}
  {}
  {\titlerule*[\dotspacing]{.}\contentspage}
  [\vspace{\linespacing}]

% subseção
\titlecontents{subsection}
  [\leftindent]
  {\normalfont\normalsize}
  {\contentslabel{\leftindent}}
  {}
  {\titlerule*[\dotspacing]{.}\contentspage}
  [\vspace{\linespacing}]

% subsubseção
\titlecontents{subsubsection}
  [\leftindent]
  {\normalfont\normalsize\itshape}
  {\contentslabel{\leftindent}}
  {}
  {\titlerule*[\dotspacing]{.}\contentspage}
  [\vspace{\linespacing}]

% incluir versões unnumbered?

% EXIGÊNCIA DA BIB@UFPR
% sumário: adiciona entrada para bibliografia e remove entradas
% de sumário, lista de figuras e lista de tabelas.
\RequirePackage[nottoc,notlot,notlof]{tocbibind}

%------------------------------------------------------------------------------

% ajustar formato das entradas nas listas de figuras e tabelas

\titlecontents{figure}
  [\leftindent]
  {\normalfont\normalsize}
  % alterado para o formato exigido pela biblioteca da UFPR
  %{\contentslabel{\leftindent}}
  {\hspace{-\leftindent} \figurename \ \thecontentslabel\ --\ }
  {}
  {\titlerule*[\dotspacing]{.}\contentspage}
  [\vspace{\linespacing}]

\titlecontents{table}
  [\leftindent]
  {\normalfont\normalsize}
  % alterado para o formato exigido pela biblioteca da UFPR
  %{\contentslabel{\leftindent}}
  {\hspace{-\leftindent} \tablename \ \thecontentslabel\ --\ }
  {}
  {\titlerule*[\dotspacing]{.}\contentspage}
  [\vspace{\linespacing}]

%------------------------------------------------------------------------------

% ajustes dos apêndices (título e sumário)

% https://stackoverflow.com/questions/717316/how-to-make-appendix-appear-in-toc-in-latex, adaptado

\newcommand\appendix@chapter[1]{%
  \refstepcounter{chapter}%
  \orig@chapter*{\@tagappendix\ \@Alph\c@chapter\enskip -- \enskip\MakeUppercase{#1}}%
  \addcontentsline{toc}{chapter}{\@tagappendix\ \@Alph\c@chapter\enskip -- \enskip\uppercase{#1}}}%
\let\orig@chapter\chapter
\g@addto@macro\appendix{\let\chapter\appendix@chapter}

%------------------------------------------------------------------------------

% endentar o primeiro parágrafo (português) em 15 mm
\setlength{\parindent}{15mm}
\IfLanguageName{brazilian}
{
  \RequirePackage{indentfirst}
}
{
  % em inglês, espaço entre parágrafos deve aumentar um pouco
}

% endentar listas de itens alinhadas aos parágrafos
\RequirePackage{enumitem}
\setlist[1]{leftmargin=\parindent}
\setlist[2]{leftmargin=0.5\parindent}

% corrigir recuos no ambiente quote
\renewenvironment{quote}{%
  \list{}{%
    \leftmargin=40mm%
    \rightmargin=0mm%
    \small%
  }%
  \item\relax}%
{\endlist}

% corrigir recuos no ambiente quotation
\renewenvironment{quotation}{%
  \list{}{%
    \leftmargin=40mm%
    \rightmargin=0mm%
    \listparindent 0.5\parindent%
    \itemindent    \listparindent
    \parsep        \z@ \@plus\p@}%
    \small%
  \item\relax}
{\endlist}

%------------------------------------------------------------------------------

% controle das legendas de tabelas e figuras
\RequirePackage{caption} 
\captionsetup{position=above}		% legenda acima da figura
\captionsetup{font=small}		% fonte menor
\captionsetup{labelfont=bf}		% rótulos em negrito
\captionsetup{skip=1ex}			% mais espaço entre legenda e tabela
\captionsetup{font+=singlespacing}	% legenda em espaço simples
\captionsetup{labelsep=endash}		% usa travessão após "Figura"
\captionsetup{justification=centering}	% legendas centralizadas
\captionsetup{singlelinecheck=false}

% Comando \source{} para figuras e tabelas
\newcommand{\source}[1]{
  % deixe esta linha em branco aqui embaixo!

  \smallskip
  {\small\textbf{\@tagsource}:~#1}
}

% Comando \note{} para figuras e tabelas
\newcommand{\note}[1]{
  % deixe esta linha em branco aqui embaixo!

  \smallskip
  {\small\textbf{\@tagnote}:~#1}
}

%------------------------------------------------------------------------------

% espaçamento entre linhas
\RequirePackage{setspace}
\iffinalmode
  \singlespacing   % final: espaçamento 1
\else
  \onehalfspacing  % default: espaçamento 1.5
\fi

% relaxar o espaçamento entre caracteres; segundo o manual
% http://texdoc.net/texmf-dist/doc/latex/l2tabu-english/l2tabuen.pdf,
% \sloppy não deve ser usado, ao invés disso usar estes parâmetros:
\tolerance 1414
\hbadness 1414
\emergencystretch 1.5em
\hfuzz 0.3pt
\widowpenalty=10000
\vfuzz \hfuzz
\raggedbottom

% impedir linhas órfãs/viúvas (linhas isoladas no início/fim de uma página)
\clubpenalty=10000
\widowpenalty=10000
\displaywidowpenalty 10000
\raggedbottom

% evitar quebra de footnotes em mais de uma página
\interfootnotelinepenalty=1000

% usar URLs na bibliografia (precisa ficar aqui pois conflita com outros pacotes)
\usepackage[obeyspaces,hyphens]{url}
\urlstyle{same}

% para adicionar imagem de fundo à capa
\RequirePackage{wallpaper}

%------------------------------------------------------------------------------

% CONTROLE DE NUMERAÇÃO DE PÁGINAS

% formatação de cabeçalho e rodapé
\RequirePackage{fancyhdr}
\setlength{\headheight}{15pt}

% sem linhas separadoras para cabeçalho e rodapé
\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{0pt}

% EXIGÊNCIA DA BIB@UFPR
% a numeração da introdução deve considerar as páginas preliminares, 
% i.e. não começa em 1). Caso as regras de sua universidade sejam "normais",
% comente as linhas abaixo.
\renewcommand\pagenumbering[1]{%
  %\global\c@page\@ne % this resets the counter
  \gdef\thepage{\csname @#1\endcsname\c@page}%
}

% define o estilo de página do preâmbulo (páginas iniciais) do documento
\fancypagestyle{frontmatter}{
  \fancyhf{}
}

% define o estilo de página do corpo do documento (capítulos)
\fancypagestyle{mainmatter}{
  \fancyhf{}
  \if@twoside
    \fancyhead[LE,RO]{\footnotesize\thepage}
  \else
    \fancyhead[R]{\footnotesize\thepage}
  \fi
}

% define o estilo default "plain" como nulo nas páginas iniciais (frontmatter)
% e igual a mainmatter no corpo do documento (para por números de página na
% primeira página de cada capítulo).
\fancypagestyle{plain}{
  \fancyhf{}
  \if@mainmatter
    \if@twoside
      \fancyhead[LE,RO]{\footnotesize\thepage}
    \else
      \fancyhead[R]{\footnotesize\thepage}
    \fi
  \fi
}

%------------------------------------------------------------------------------

% CONTROLE DO PDF GERADO

% pacotes para gerar um arquivo PDF "rico" (bookmarks, links, metadados)
\RequirePackage[plainpages,pdfpagelabels]{hyperref}	% PDF com links, metadados
\RequirePackage{bookmark}				% cria um índice no PDF

% ajustar metadados e propriedades do PDF gerado
\hypersetup{
  % pdftitle, author, etc definidos mais abaixo
%  bookmarks   = true,
%  pageanchor  = false,
  hypertexnames = false,
%  bookmarkstype = page,
  pdfview     = Fit,
  pdfborder   = {0 0 0},
  colorlinks  = false,
  linkcolor   = blue,
  anchorcolor = blue,
  citecolor   = blue,
  filecolor   = blue,
%  pagecolor   = blue,
  urlcolor    = blue
}

% suprimir mensagens de erro "Token not allowed in a PDF string"
\pdfstringdefDisableCommands{%
  \let\uppercase\relax
  \let\MakeUppercase\relax
  \let\hskip\relax
}

\RequirePackage{microtype}	% melhorar a qualidade da tipografia no PDF

%------------------------------------------------------------------------------

% COMANDOS PARA DEFINIÇÕES FEITAS NO MAIN.TEX

% definição de autor, orientador, local, área, palavras-chave, etc
% valores default (não mudá-los, pois poderão ser testados em macros)
\def\@advisor{}			% orientador
\def\@coadvisor{}		% coorientador
\def\@field{}			% área de concentração
\def\@local{}			% local
\def\@descr{}			% descrição do documento
\def\@instshort{undef}		% instituição (abreviação)
\def\@instlong{undef}		% instituição (por extenso)
\def\@pcs{}			% palavras-chave
\def\@kws{}			% keywords
\def\@coverimg{}		% imagem de fundo da capa

% instituição
\newcommand{\instit}[2]{
  \def\@instshort{#1}
  \def\@instlong{#2}
}

% descrição do documento na folha de rosto
\newcommand{\descr}[1]{\def\@descr{#1}}

% orientadores
\newcommand{\advisor}[1]{\def\@advisor{#1}}
\newcommand{\coadvisor}[1]{\def\@coadvisor{#1}}

% área/tema do texto
\newcommand{\field}[1]{\def\@field{#1}}

% local (cidade)
\newcommand{\local}[1]{\def\@local{#1}}

% palavras-chave em português e inglês
\newcommand{\pchave}[1]{\def\@pcs{#1}}
\newcommand{\keyword}[1]{\def\@kws{#1}}

% imagem de fundo da capa
\newcommand{\coverimage}[1]{\def\@coverimg{#1}}

%------------------------------------------------------------------------------

% AMBIENTES DA PARTE INICIAL DO DOCUMENTO

% ficha catalográfica
\newenvironment{ficha}
{
  \if@twoside
    % nada
  \else
    \addtocounter{page}{-1} % não conta no número de páginas (BIB@UFPR)
  \fi
}
{\clearpage}

% folha de aprovação
\newenvironment{aprovacao}
{}
{\cleardoublepage}

% agradecimentos
\newenvironment{agradece}
{
  \chapter*{\MakeUppercase\@chapthanks}
}{
  \vfill
  \cleardoublepage
}

% dedicatória
\newenvironment{dedica}
{
  \vspace*{\fill}
  \hfill
  \begin{minipage}[t]{6cm}
  \em
}{
  \end{minipage}
  \cleardoublepage
}

% resumo
\newenvironment{resumo}
{
  \chapter*{RESUMO}
  % texto deve ser formatado em português
  \begin{otherlanguage}{brazilian}
}{
  % somente mostrar palavras-chave se estiverem definidas
  \ifx\@pcs\@empty
  \else
    \vspace{3ex}
    \noindent{\textbf{Palavras-chave}:} {\@pcs}
  \fi
  \end{otherlanguage}
  \vfill
  \cleardoublepage
}

% abstract
\newenvironment{abstract}
{
  \chapter*{ABSTRACT}
  % texto deve ser formatado em inglês
  \begin{otherlanguage}{english}
}{
  % somente mostrar keywords se estiverem definidas
  \ifx\@kws\@empty
  \else
    \vspace{3ex}
    \noindent{\textbf{Keywords}:} {\@kws}
  \fi
  \end{otherlanguage}
  \vfill
  \cleardoublepage
}

% alguns ambientes só aparecem na versão final
\iffinalmode
  % nada
\else
  % na versão de defesa, esses ambientes não geram nada
  \renewenvironment{ficha}     {\comment} {\endcomment}
  \renewenvironment{aprovacao} {\comment} {\endcomment}
  \renewenvironment{agradece}  {\comment} {\endcomment}
  \renewenvironment{dedica}    {\comment} {\endcomment}
\fi

%------------------------------------------------------------------------------

% listas de figuras e tabelas, sumário, referências
% ajustes feitos usando comandos do pacote Babel
\IfLanguageName{brazilian}
{
  \addto{\captionsbrazilian}
  {
    \renewcommand{\listfigurename}{LISTA DE FIGURAS}
    \renewcommand{\listtablename}{LISTA DE TABELAS}
    \renewcommand{\contentsname}{SUM\'ARIO}
    \renewcommand{\bibname}{REFER\^ENCIAS}
    % outros campos em .../babel-portuges/portuges.ldf
  }
}
{
  \addto{\captionsenglish}
  {
    \renewcommand{\listfigurename}{LIST OF FIGURES}
    \renewcommand{\listtablename}{LIST OF TABLES}
    \renewcommand{\contentsname}{CONTENTS}
    \renewcommand{\bibname}{REFERENCES}
  }
}

% lista de acrônimos (abreviaturas e Siglas)
\newenvironment{listaabrev}
{
  \chapter*{\@listabbrevs}
  \begin{spacing}{1.25}  % a lista deve ter espaçamento 1,25
}{
  \end{spacing}
  \vfill
  \cleardoublepage
}

% lista de símbolos
\newenvironment{listasimb}
{
  \chapter*{\@listsymbols}
  \begin{spacing}{1.25}  % a lista deve ter espaçamento 1,25
}{
  \end{spacing}
  \vfill
  \cleardoublepage
}

%------------------------------------------------------------------------------

% CONSTRUÇÃO DAS PÁGINAS INICIAIS

\renewcommand{\titlepage}
{
  % ajustar metadados do PDF final (só funciona bem se estiver aqui)
  \ifmetadata
    \hypersetup{
      pdftitle    = {\@title},
      pdfauthor   = {\@author},
      pdfsubject  = {\@field},
      pdfproducer = {\@instshort\ - \@instlong},
      pdfcreator  = {LaTeX, using PPGInf/UFPR class},
      pdfkeywords = {\@pcs, \@kws}
    }
  \else
    \hypersetup{
      pdftitle    = {},
      pdfauthor   = {},
      pdfsubject  = {},
      pdfproducer = {},
      pdfcreator  = {},
      pdfkeywords = {}
    }
    \pdfinfoomitdate 1
  \fi

  % PRIMEIRA CAPA (SÓ NA VERSÃO APROVADA)

  \iffinalmode

    % imagem de fundo da capa, se estiver definida em main.tex
    \ifx\@coverimg\@empty
    \else
      \ThisCenterWallPaper{1.0}{\@coverimg}
    \fi

    % conteúdo da capa
    \begin{center}
      \begin{doublespace}
        \MakeUppercase{\@instlong}
        \\
        \vspace{2cm}
        \MakeUppercase{\@author}
        \\
        \vfill
        \vspace{-1cm}
        \DeclareRobustCommand\\{\linebreak}
        \MakeUppercase{\@title}
        \vfill
        \MakeUppercase{\@local} \\
        \MakeUppercase{\@date}
      \end{doublespace}
    \end{center}
    \cleardoublepage

    % EXIGÊNCIA DA BIB@UFPR
    % reiniciar numeração de páginas, para não contar a capa;
    % segundo a bib@UFPR a capa não deve contar como página
    \setcounter{page}{1}
  \fi

%  \clearpage

  % FOLHA DE ROSTO

  % autor
  \begin{center}
    \MakeUppercase{\@author}
  \end{center}

  % maior espaço em branco
  \vfill\vfill

  % título
  \begin{doublespace}
    \begin{center}
      \DeclareRobustCommand\\{\linebreak }
      \MakeUppercase{\@title}
    \end{center}
  \end{doublespace}

  % na versão de defesa, indicar data de compilação do documento
  \iffinalmode
    % do nothing
  \else
    \begin{small}
    \begin{center}
      \IfLanguageName{brazilian}
      {
        (\emph{vers\~ao pr\'e-defesa, compilada em \today})
      }{
        (\emph{pre-defense version, compiled at \today})
      }
    \end{center}
    \end{small}
  \fi

  % 2 linhas espaço 1.5
  \vspace{2em}

  % construção do selo descritivo
  \hfill
  \begin{minipage}{8cm}
  \begin{footnotesize}

    % descrição do documento, se estiver definida em main.tex
    \ifx\@descr\@empty
    \else
      \@descr.
    \fi

    % área de concentração, se estiver definida em main.tex
    \ifx\@field\@empty
    \else
      % 1 linha espaço 1.5
      \vspace{1em}
      \@tagfield: \emph{\@field}.
    \fi

    % orientador, se estiver definido em main.tex
    \ifx\@advisor\@empty
    \else
      % 1 linha espaço 1.5
      \vspace{1em}
      \@tagadvisor: \@advisor.
    \fi

    % coorientador, se estiver definido em main.tex
    \ifx\@coadvisor\@empty
    \else
      % 1 linha espaço 1.5
      \vspace{1em}
      \@tagcoadvisor: \@coadvisor.
    \fi

  \end{footnotesize}
  \end{minipage}

  % menor espaço em branco
  \vfill

  % local e data
  \begin{center}
    \begin{doublespace}
      \MakeUppercase{\@local} \\
      \MakeUppercase{\@date}
    \end{doublespace}
  \end{center}

  % encerra esta página; a ficha catalográfica vem a seguir, no verso
  \clearpage

  % that's all, folks!
}

%------------------------------------------------------------------------------
