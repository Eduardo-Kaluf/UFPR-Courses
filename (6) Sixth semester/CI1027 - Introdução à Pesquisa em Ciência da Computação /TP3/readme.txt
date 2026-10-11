Modelo LaTeX de dissertação/tese do PPGInf/UFPR
Autor: prof. Carlos A. Maziero (maziero@inf.ufpr.br)
http://wiki.inf.ufpr.br/maziero/doku.php?id=software:latex
https://gitlab.c3sl.ufpr.br/maziero/tese

Descrição:

Modelo LaTeX para dissertações, teses, qualificações, trabalhos finais de graduação
e outros documentos similares. Previamente configurado para o PPGInf/UFPR, mas pode
ser facilmente ajustado para outros programas, cursos e universidades.

Conteúdo:

  ppginf.cls		: classe com as principais características do modelo
  main.tex		: fonte principal, que inclui os demais
  packages.tex		: inclusão de packages úteis para a redação
  referencias.bib	: referências bibliográficas (BibTeX)
  0-iniciais/		: diretório com as páginas iniciais
      resumo.tex	: resumo e palavras-chave
      abstract.tex	: abstract and keywords
      agradece.tex	: agradecimentos
      dedica.tex	: dedicatória
      aprovacao.tex	: inclusão da folha de aprovação
      aprovacao.pdf	: folha de aprovação "fake"
      catalografica.tex	: inclusão da ficha catalográfica
      catalografica.pdf	: ficha catalográfica "fake"
      abreviaturas.tex	: lista de abreviaturas e siglas
      simbolos.tex	: lista de símbolos
      fundo-capa.jpg	: imagem de fundo da capa
  1-intro/		: diretório do capítulo 1 (Introdução)
      texto.tex		: texto do capítulo 1
      figuras/		: figuras do capítulo 1
  2-fundam/		: ... (idem)
  a1-exemplo/		: Anexo 1
  Makefile		: usado para construir o PDF ;-)

Para compilar, digite "make".

Para atualizar seu modelo, caso já o esteja usando:

  1) baixar a última versão em https://gitlab.c3sl.ufpr.br/maziero/tese
  2) substituir os arquivos ppginf.cls e packages.tex
  3) verificar se há diferenças entre os arquivos main.tex (o seu e o do modelo)

Pendências (há voluntários?):

- automatizar a geração das lista de símbolos e abreviações
- automatizar geração da ficha catalográfica
- posicionar ficha catalográfica no verso da 2a capa
- criar capítulos com conteúdo básico de uma dissertação ou tese
- distribuir melhor os pacotes entre ppginf.cls e packages.tex
- incluir uma 2a folha de rosto em inglês para documentos em inglês
- analisar uso de \backmatter
- separar apêndices de anexos?
- diferenciar tabelas de quadros?
- mudar da classe book para memoir?

