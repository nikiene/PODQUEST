# **PODQUEST**
EP-1 | Estrutura de Dados - 3° Semestre -  Bacharelado em Ciência da Computação - Senac Santo Amaro

# 1. **PODQUEST MVP**

  * Quero poder inserir um novo podcast na minha playlist, para depois poder verificar quais são os episódios de podcasts que tenho

  * Quando inserir meu episódio, quero poder colocar algumas palavras-chave, pra poder buscar depois através delas

  * Quero poder remover um episodio de podcast, caso eu não queira mais ouvi-lo

  * Quero poder começar a tocar minha playlist e saber qual podcast esta sendo reproduzido no momento, para poder verificar se quero ouvir aquele ou se passo para o próximo 

  * Quero poder escolher a opção “shuffle” que, ao passar para o próximo podcast, escolhe um episódio aleatório da minha playlist para tocá-lo

  * Quero saber quais são e quantos são os podcasts (se tiver mais de um episódio do mesmo podcast, quero saber só o nome deste podcast) que possuo na minha playlist, para poder contar para os meus amigos

# 2. **Especificações**

  * Um episodio de podcast terá as seguintes informações:
  
      * Nome do Podcast, com no máximo 64 caracteres
      
      * PodcastId, um número inteiro que identifica aquele podcast
      
      * Nome do Episódio, com no máximo 64 caracteres
      
      * Um número inteiro que representará qual é o episódio 
      
      * Uma lista com palavras-chave do episódio, cada palavra tendo no máximo 64 caracteres

# 3. **Execução**

 * adicionar : pede as informações do episódio e o insere no fim da playlist | pedir palavras-chave (Opcional)

 * remover   : pede pelo id do podcast e o número do podcast para poder removê-lo da lista, avisando o usuário após a remoção

 * tocar     : imprime o episódio atual

 * shuffle   : ativa/desativa a opção de shuffle e avisa o usuário

 * próximo   : imprime o próximo episódio na lista. Se a opção shuffle estiver ativada, deve ser um episódio aleatório, diferente da ordem que foram inseridos

 * relatório :  o programa imprime quais são os podcasts que existem na playlist, algo como “2 podcasts na sua playlist! Veja abaixo quais sao:”, com a lista de nomes, um por linha
