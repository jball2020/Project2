Project: Project 2
Author: Jordan Ball
Date: 3/2/2018


Description:
	This project implements a MinHeap and a Huffman tree. The user can run an input file on the executable that has the following format:
	Format							Example:
	----------------------			-----------------------
	int n, number of cases			3
	string message 1				opossum
	string message 2				hello world			 	
	       .						message				  	
		   .						-----------------------
		   .
	string message n
	----------------------
	This program takes the messages and outputs them in a encoded form as per the Huffman coding algorithm accomplished by the HuffmanTree

	Example output:
	------------------------------------------
	Test Case: 1
	11 00 11 10 10 011 010 
	Test Case: 2
	010 011 10 10 00 1100 1101 00 1110 10 1111 
	Test Case: 3
	011 10 11 11 010 00 10 
	------------------------------------------


Build Instructions:
	To build with the include makefile:
		type make
