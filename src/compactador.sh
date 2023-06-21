#!/bin/bash

anos="09 10 11 12 13 14 15 16 17 18 19 20"
estados="SC RS PR SP RJ MG ES MT MS GO DF"

for xx in $anos; do
    arquivo_saida="dataset20${xx}.tar.gz"
    arquivos_csv=""

    # Concatenar todos os arquivos CSV em uma única string
    for yy in $estados; do
        arquivo_csv="anos/20${xx}/20${xx}-${yy}.csv"
        arquivos_csv="$arquivos_csv $arquivo_csv"
    done
        arquivo_csvLocal="ano/20${xx}/20${xx}.csv"
        arquivos_csv="$arquivos_csv $darquivo_csvLodcal"

    # Adicionar o arquivo sguf à string
    arquivo_sguf="anos/20${xx}/sguf"
    arquivos_csv="$arquivos_csv $arquivo_sguf"

    # Compactar os arquivos usando tar e gzip
    zip -j "$arquivo_saida" $arquivos_csv

    echo "Arquivos 20${xx} compactados em $arquivo_saida"
done

