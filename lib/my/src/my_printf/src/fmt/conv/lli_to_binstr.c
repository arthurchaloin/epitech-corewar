/*
** lli_to_binstr.c for my_printf in /home/arbona/Projects/PSU_2016_my_printf/lib/my/src/my_printf
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Thu Nov 17 09:24:22 2016 Thomas ARBONA
** Last update Sun Mar 26 03:10:40 2017 Thomas ARBONA
*/
#include "../../../include/fmt.h"

char		*lli_to_binstr(t_specs_data *sdata, t_pfargs *pfargs)
{
  t_ulli	nb;
  char		*out;
  int		len;
  char		*prec;

  nb = get_nbarg(sdata, pfargs);
  out = lli_to_basestr(nb, BASE_BINARY);
  if (nb == 0 && sdata->prec == 0)
    out[0] = '\0';
  if (sdata->flags & ALTFLAG && out[0] != '0')
    out = my_str_concat("0", out);
  if (my_strlen(out) >= sdata->prec)
    return (out);
  len = sdata->prec - my_strlen(out) + 1;
  if (!(prec = malloc(sizeof(char) * len)))
    return (NULL);
  my_memset(prec, '0', len);
  return (my_str_concat(prec, out));
}
