#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_verif.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 19:51:27 by gustaoli          #+#    #+#              #
#    Updated: 2025/08/01 19:51:28 by gustaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Este script clona um repositório e abre o code num diretório temporário

# Configure seu terminal para rodar o script:

# Acesse o arquivo de config do zsh
# >nano ~/.zshrc

# Adicione o alias para chamar o script (defina o cominho de onde instalar) e salve o arquivo
# >alias ft_verif=(caminho do script)/ft_verif.sh

# Atualize o zsh
# >source ~/.zshrc

# Dê permissão de execução ao arquivo
# >chmod 777 ft_verif.sh

# Scrip configurado :)

rm -rf ~/Desktop/.temp

mkdir ~/Desktop/.temp

echo -e "Clonando respositório\n"
if git clone $1 ~/Desktop/.temp -q; then
	code ~/Desktop/.temp/.
else
	echo "❌ Git clone falhou ❌"
fi

echo "🤘"
