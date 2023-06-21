#!/bin/bash

anos="09 10 11 12 13 14 15 16 17 18 19 20"
estados="SC RS PR SP RJ MG ES MT MS GO DF"

for xx in $anos; do
    for yy in $estados; do
        arquivo="anos/20${xx}/20${xx}-${yy}.csv"
        resultado="20${xx}-${yy}-Resultado"

        ./calculaMediaEDesvio "$arquivo" "$resultado" ","
    done
done

# apenas para linux