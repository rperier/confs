NAME = linux-reset-controller.tex
OUTNAME = reset_framework_architecture.png linux-reset-controller.pdf

%.png: %.dia
	dia -t png -e $@ $<
%.pdf: %.tex
	rubber -d $<
all: $(OUTNAME)

clean:
	$(RM) *.toc *.txt *.out *.snm *.nav *.aux *.log $(OUTNAME)

