# Makefile básico, sugestões são bem-vindas...
# Carlos Maziero @UFPR, out 2017

MAIN=main
OUTPUT=$(MAIN)_$(USER).pdf	# a pedido da coordenacao

main: $(MAIN).tex
	@pdflatex $(MAIN)
	@bibtex   $(MAIN)
	@pdflatex $(MAIN)
	@pdflatex $(MAIN)
	@mv $(MAIN).pdf $(OUTPUT)

bib:
	@bibtex $(MAIN)

# dessa forma somente os arquivos removidos são listados na saída
clean:
	@find . -xdev -iname \*~    -print -delete
	@find . -xdev -iname \*.aux -print -delete
	-rm -f texput.log
	-rm -f $(MAIN).log $(MAIN).lot $(MAIN).lof
	-rm -f $(MAIN).toc $(MAIN).bbl $(MAIN).blg
	-rm -f $(MAIN).acr $(MAIN).smb

purge: clean
	@rm -f $(OUTPUT)

