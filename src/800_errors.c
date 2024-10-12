/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   800_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:41:19 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/26 20:20:51 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Print a general error message
 * @param msg The error message to be printed
 * @return FAILURE(Always returns FAILURE to indicate an error occurred)
 * @details
 * This function prints a general error message to the standard output.
 * It prefixes the message with "Error\n" for consistency in error reporting.
 */
int	ft_err(char	*msg)
{
	printf("Error\n%s\n", msg);
	return (FAILURE);
}

/**
 * @brief Print a file-related error message
 * @param file The name of the file that caused the error
 * @return FAILURE(Always returns FAILURE to indicate an error occurred)
 * @details
 * This function prints an error message related to file operations.
 * It uses a predefined FILE_ERR format string to ensure consistent
 * formatting of file error messages.
 */
int	ft_file_err(char *file)
{
	printf("Error\n");
	printf(FILE_ERR, file);
	printf("\n");
	return (FAILURE);
}

/**
 * @brief Print a map parsing error message
 * @param msg The specific parsing error message
 * @return FAILURE(Always returns FAILURE to indicate an error occurred)
 * @details
 * This function prints an error message specific to map parsing issues.
 * It provides context by mentioning that the error occurred during map parsing
 */
int	ft_parse_err(char *msg)
{
	printf("Error\nThere was a problem while parsing the map: %s\n", msg);
	return (FAILURE);
}

/**
 * @brief Print a map size error message
 * @param width Bool indicating whether the error is related to width or height
 * @param expected The expected size
 * @param got The actual size encountered
 * @return FAILURE(Always returns FAILURE to indicate an error occurred)
 * @details
 * This function prints a detailed error message when there's a mismatch
 * in the map's dimensions. It specifies whether the issue is with the
 * width or height and provides both the expected and actual sizes.
 */
int	ft_parse_size_err(t_bool width, size_t expected, size_t got)
{
	printf("Error\nThere was a problem while parsing the map: %s\n",
		PARSE_SIZE);
	if (width)
		printf("width");
	else
		printf("height");
	printf(" | expected %lu -> has %lu\n", expected, got);
	return (FAILURE);
}
