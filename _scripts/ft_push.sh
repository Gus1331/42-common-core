#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    push.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 16:27:07 by gustaoli          #+#    #+#              #
#    Updated: 2025/08/01 16:27:08 by gustaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Este script define o repositório para submeter ao link passado como parâmetro

# Configure seu terminal para rodar o script:

# Acesse o arquivo de config do zsh
# >nano ~/.zshrc

# Adicione o alias para chamar o script (defina o cominho de onde instalar) e salve o arquivo
# >alias ft_push=(caminho do script)/ft_push.sh

# Atualize o zsh
# >source ~/.zshrc

# Dê permissão de execução ao arquivo
# >chmod 777 ft_push.sh

# Scrip configurado :)

# Remova "> /dev/null 2>&1" de comandos que queira desilenciar

# Nome do usuário atual
USER_NAME=$(whoami)

echo -e "${USER_NAME} 🤘 >> $1\n"

# Padrão fixo no início da string

# Regex básico nosso de cada dia pra validar o link do projeto
REGEX="^git@vogsphere-v2\.42sp\.org\.br:vogsphere/intra-uuid-[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}-[0-9]+-${USER_NAME}$"

Validação Input x Regex
if [[ ! $1 =~ $REGEX ]]; then
	echo -e "❌ Link do projeto inválido ❌\n"
	exit 1
fi

# Valida se já existe um repositório neste local
if [ -d "$(pwd)/.git" ]; then
	echo "❌ Já existe um .git neste repostório ❌"
	exit 1
fi

# Iniciando novo repositório...
git init > /dev/null 2>&1

# Linkando com repositório remoto
git remote add origin $1

# Adicionando mudanças ao repositório
git add -A

echo "Subindo arquivos:"
git diff --cached --name-only
echo ""

# Puxa quaisquer coisas já submetidas, caso contrário dará merge
#git pull --set-upstream origin master --allow-unrelated-histories > /dev/null 2>&1

if ! norminette > /dev/null 2>&1; then
	echo -e "⚠️ ⚠️ ⚠️ Há possíveis erro de Norminette! ⚠️ ⚠️ ⚠️\n"
fi

# Commitando ..
git commit -m"feat: add $(basename "$PWD")" > /dev/null 2>&1

# Realizando push
echo "📤 Subindo para o remoto..."
if git push --set-upstream origin master --force > /dev/null 2>&1 ; then
	echo -e "✅ Projeto submetido com sucesso! ✅\n"
else
	echo -e "❌ Não foi possível realizar o push ❌\n"
	rm -rf .git
	exit 1
fi

# Limpa o repositório criado
rm -rf .git

