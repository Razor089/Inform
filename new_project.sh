#!/bin/zsh

echo "Creazione cartella..."
mkdir Games/$1

echo "Creazione file di compilazione..."
echo "inform +include_path=./,../../Lib/Base,../../Lib/Contrib +language_name=italian $1.inf" >> Games/$1/compile.sh
echo "inform -G +include_path=./,../../Lib/Base,../../Lib/Contrib +language_name=italian $1.inf" >> Games/$1/compile_glux.sh

echo "Rendendo eseguibile i file shell..."
chmod +x Games/$1/compile.sh Games/$1/compile_glux.sh

echo "Creazione file principale..."
touch Games/$1/$1.inf

echo "Finito..."
open Games/$1
