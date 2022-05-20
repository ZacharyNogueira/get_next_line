#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0; 
	if (!s)
		return (0);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	int		i;
	int		len;

	len = ft_strlen(s) + 1;
	result = malloc(sizeof(char) * len);
	if (!result)
		return (0);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*result;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(sizeof(char) * len);
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (0);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}