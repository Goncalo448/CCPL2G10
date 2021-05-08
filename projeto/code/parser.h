/**
 * @file Library Parser
 */

/**
 * \brief Esta função retorna um inteiro que indica qual o tipo de operações 
 */
int verifica_token(char const *token);


char *get_token(char *line, char **rest);


char *get_delimited(char *line, char **rest);

/**
 * \brief Função que faz parse ao input.
 */
void parse(char *input);


