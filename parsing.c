#include "ft_printf.h"

int		ft_search_char(char *str, char c)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == c)
			return(1);
		i++;
	}
	return(0);
}

char*	ft_str_cut(char *str, int len)
{
	char *result;
	int i;

	result = ft_strnew(ft_strlen(str));
	i = 0;
	while(i != len + 1)
	{
		result[i] = str[i];
		i++;
	}
	result[i] == '\0';
	return (result);
}
char*	ft_parsing(char *str)
{
	char *tmp;
	char *mod;
	int i;

	i = 0;
	mod = "diuoxXfFeEgGaAcsSpn";
	tmp = ft_strdup(str);
	while(tmp[i] != '\0')
	{
		if (tmp[i] == '%')
		{
			while(ft_search_char(mod, tmp[i]) != 1 || tmp[i] != '\0')
				i++;
			tmp = ft_str_cut(tmp, i);
			//Дальше переносим строку в структуру
			ft_strclr(tmp);
			tmp = ft_strdup(str);
			//tmp = ft_strsub(str, i + 1, ft_strlen(str));
		}
		i++;
	}
	return tmp;
}