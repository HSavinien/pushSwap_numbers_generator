# pushSwap_numbers_generator
a basic random generator, made with 42's push swap in mind. allow to generate a list of n numbers in a specifiable range

## usage

### how to call
the program is called with
`./get_nbrs <lst_len> [min|max] [max]`
where : 
- `lst_len` is the number of elements in the list;
- `min|max` is either the upper or lower limit of your range;
- `max` is the upper limit of your range;

If only one argument is specified, the range will default from 0 to lst_len;

If two arguments are specified, the second argument indicate the upper limit of the range, and le lower limit default to 0;

If all three arguments are specified, the second is the lower limit of range, and the third the upper one.

As of now, generating negative number is unsuported. as such, both range delimiter must be positive numbers.

### how to use
used alone, the program will display the generated list on std_out, with each numbers separated by a single space, and folowed by a newline. this formating should be useable as is by any push_swap.
since the project push_swap does not read std_in, using `./get_nbrs 10 | ./push_swap` might not work. 
while copy-past is a solution, a better solution is to use shell variables. for example with this comand :
`NBRS=$(./get_nbrs 10) ; ./push_swap $NBRS`

## context and principe
### why?
42 school's push swap project require, both for testing and correction, a list of number that can get quite long (up to 500 numbers). Thoses number must be in disorder, and cannot repeat themselves.
In addition to being a realy boring idea, typing thoses numbers by hand make it unlikly to get a realy random patern, and checking for duplicate would be realy hard. So a programe doing it for us, better and faster, is needed. 
But despite the obvious need and the simplicity of the idea, I could not find anything online. So I choose to make a basic program answering my need.

### principe
the progam is one of the most basic way of aswering the problem : it generate random numbers without duplicate, and put them directly to std_out. the formating of the output is also the formating of push_swap input.
the program is coded in C. it might be one of the most stupid langage for that project, but it was the only one fresh in my mind when I did it.
it is coded to pass 42 norm, so you can include it in your project repository. but it uses a lot of forbiden functions, so make sure to keep it by itself, and clearly not a part of the main project.

