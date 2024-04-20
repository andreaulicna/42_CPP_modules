/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:02:33 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/20 22:04:40 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.class.hpp"

/**
 * Real-life use cases for Serializer class (simplified).
 * 
 * Storing Pointers to Disk: If we have a pointer to an object in memory and
 * want to save this pointer to a file or database for later use, we can't just
 * write the pointer value directly. This is because the actual address
 * the pointer points to may not be valid or may point to a different object
 * when our program is run again in the future. Instead, we can use
 * the serialize function to convert the pointer to a uintptr_t, which
 * can be safely written to disk. Later, when we read the value back from disk,
 * we can use the deserialize function to convert it back to a pointer.
 * 
 * Sending Pointers over a Network: If we want to send a pointer to an object
 * over a network, we can't just send the pointer value directly, because
 * the address the pointer points to won't be valid on the receiving machine.
 * Instead, yweou can serialize the pointer to a uintptr_t, send this value over
 * the network, and then deserialize it back to a pointer on the receiving end.
 * 
 * Storing Pointers in a Portable Format: If we are working with a system that
 * needs to store pointers in a format that can be used across different
 * platforms (for example, a 32-bit system and a 64-bit system), we can use
 * the serialize function to convert the pointers to uintptr_t, which is
 * a portable format. We can then use the deserialize function to convert them
 * back to pointers on the target system.
*/

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(const Serializer& copy)
{
	*this = copy;
}

Serializer	&Serializer::operator = (const Serializer &src)
{
	(void) src;
	return (*this);
}

Serializer::~Serializer(void)
{
	return ;
}

/**
 * @brief	Serializes a Data pointer into a uintptr_t.
 * 
 * This function takes a pointer to a Data object and converts it into
 * a uintptr_t. This is useful for storing the pointer in a format that
 * can be safely written to disk.
 * 
 * reinterpret_cast allows us to read the passed memory in a different way.
 * We give it a memory location and ask it to read that memory as if it was what
 * we asked it to. This is why it can only be used with pointers and references.
 * 
 * @param	ptr			Data pointer to serialize
 * @return	uintptr_t	serialized pointer as a uintptr_t
 */
uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief	Deserializes a uintptr_t into a Data pointer.
 * 
 * This function takes a serialized Data pointer (in the form of a uintptr_t)
 * and converts it back into a Data pointer. This is useful for reading
 * a serialized pointer from disk and converting it back into a usable form.
 * 
 * reinterpret_cast allows us to read the passed memory in a different way.
 * We give it a memory location and ask it to read that memory as if it was what
 * we asked it to. This is why it can only be used with pointers and references.
 * 
 * @param	raw		uintptr_t to deserialize
 * @return	Data*	deserialized pointer as a Data pointer
 */
Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
