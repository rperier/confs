NAME = linux-reset-controller.tex

all:
	rubber -d $(NAME)
clean:
	$(RM) *.toc *.txt *.out *.snm *.nav *.aux *.log *.pdf

