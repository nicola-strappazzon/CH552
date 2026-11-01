SHELL := /bin/bash
export PATH := $(PATH):/Library/TeX/texbin:/opt/homebrew/bin:/usr/local/bin
FILE := ch552g
ASSET := ../../assets/pinout2.png

.PHONY: build clean

build: $(FILE).pdf $(FILE).svg $(FILE).png $(ASSET)

$(FILE).pdf: $(FILE).tex pins.tex groups.tex
	pdflatex -interaction=nonstopmode -halt-on-error -file-line-error $(FILE).tex

$(FILE).svg: $(FILE).pdf
	pdf2svg $< $@

$(FILE).png: $(FILE).pdf
	pdftoppm -r 200 -png -singlefile $< $(FILE)

$(ASSET): $(FILE).png
	mkdir -p $(dir $@)
	cp $< $@

clean:
	rm -f $(FILE).aux $(FILE).log
