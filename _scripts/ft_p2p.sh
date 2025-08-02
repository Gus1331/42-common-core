#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_p2p.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 20:09:44 by gustaoli          #+#    #+#              #
#    Updated: 2025/08/01 20:09:45 by gustaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Este script clona um repositório respeitando minha organização de avaliações p2p

# Configure seu terminal para rodar o script:

# Acesse o arquivo de config do zsh
# >nano ~/.zshrc

# Adicione o alias para chamar o script (defina o cominho de onde instalar) e salve o arquivo
# >alias ft_p2p=(caminho do script)/ft_p2p.sh

# Atualize o zsh
# >source ~/.zshrc

# Dê permissão de execução ao arquivo
# >chmod 777 ft_p2p.sh

# Scrip configurado :)

# Diretório de avaliações
AV_DIR=~/Desktop/avaliacoes

# Conta a qtd de avaliações existentes
NUM_DIRS=$(find "$AV_DIR" -mindepth 1 -maxdepth 1 -type d | wc -l)

# Gera o numero da nova av
AV_INDEX=$((NUM_DIRS + 1))

# Gera o nome da nova av
NEW_AV=$(printf "av%03d" "$AV_INDEX")

echo -e "\n Avaliação n: $(printf "%03d" "$AV_INDEX") 🤘\n \n"

# Clona a 
if git clone "$1" "$AV_DIR/$NEW_AV" > /dev/null 2>&1; then
	echo -e "\nAvaliação iniciada...\n"
	sleep 2
	code "$AV_DIR/$NEW_AV"
else
	echo -e "❌ Erro ao clonar repositório ❌\n"
fi
