/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:28:39 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/06 14:41:17 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", "default",
	145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("shrubbery creation",
	target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this == &rhs)
		return (*this);
	AForm::operator=(rhs);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	AForm::formExec(bureaucrat);
	std::ofstream ofs ((this->getTarget() + "_shruberry").c_str());
	if (!ofs.is_open())
		std::cerr << RED << "Error opening file" << this->getTarget() << "_shruberry" << RST << std::endl;
	ofs << "********************************** Drawing of a Shrubbery trees ***********************************" << std::endl;
	ofs << "*                                                                                                 *" << std::endl;
	ofs << "*                                           =*+=                                                  *" << std::endl;    
	ofs << "*                                          @:  .%                                                 *" << std::endl;    
	ofs << "*                                         @     -%                                                *" << std::endl;    
	ofs << "*                                        @       =.                                               *" << std::endl;    
	ofs << "*                                       --       :*                                               *" << std::endl;    
	ofs << "*                                       @         =+                                              *" << std::endl;    
	ofs << "*                                      @:          +                                              *" << std::endl;    
	ofs << "*                      -#########     ::           +-                                             *" << std::endl;    
	ofs << "*                    -#-          ##. %:            *:                                            *" << std::endl;    
	ofs << "*                   :.              =*=             *-                                            *" << std::endl;    
	ofs << "*                  -#                -%             .:                           .###*            *" << std::endl;    
	ofs << "*                  -+                .-              %+#.                     .##=    #:          *" << std::endl;    
	ofs << "*                  #                 #=              %. -####                ##        +#         *" << std::endl;    
	ofs << "*                  #                 :               *       :#             #            *#       *" << std::endl;    
	ofs << "*                 =                  =               :=       =.  *- %    ##              #       *" << std::endl;    
	ofs << "*                 .#                -*                *        =%#.   *@  #                #      *" << std::endl;    
	ofs << "*                  #                +#                @        -=       #%                 +#     *" << std::endl;    
	ofs << "*                  :                :-                @       @=         ..                 .*    *" << std::endl;    
	ofs << "*                  #                ..                %      @            @                  =.   *" << std::endl;    
	ofs << "*                  #                +*                #     @              @                 +#   *" << std::endl;    
	ofs << "*             #@  =%.               -=                #    @                @                :*   *" << std::endl;    
	ofs << "*            @      =*              +#                *    @                -                 *+  *" << std::endl;    
	ofs << "*           #        --             =#               :-   +.                .#                -+  *" << std::endl;    
	ofs << "*          @          *-             -               *.   -:                 *                 #: *" << std::endl;    
	ofs << "*          *           =             :-   -       .  %:   .#                 :                -*  *" << std::endl;    
	ofs << "*         @:           @+           +#%:    +#*%    +=    @                  +                 #  *" << std::endl;    
	ofs << "*        ::            :           =-   %-+-@  +.%@*      +                 .@                 *: *" << std::endl;    
	ofs << "*        =:            .####. @.#*#         @ .=           @                 %                 *  *" << std::endl;    
	ofs << "*        -:                +  @             @ :%*+         %+  :  =#-@..   :@                 *=  *" << std::endl;    
	ofs << "*         @+           %*  =  @             @ .- =#+% .+=##  -#** @. .  @:*                  :#   *" << std::endl;    
	ofs << "*          #%   @ @+ +@-   +  @             @ .+    + ::          %. #-.#-                  ##    *" << std::endl;    
	ofs << "*            -=-@ @ -      +  @             @ .+    + -:          *. :    +##**#*@= @. #**##      *" << std::endl;    
	ofs << "*               + @        -  @             @  -      .           =              *  =             *" << std::endl;    
	ofs << "*       .######@@=@*#######@%-@=###########+@=%@*%#@@#@@#########*@@*@@##@%@@@@@*@@+@#@@@@@@@@@@* *" << std::endl;
	ofs << "*                                                                                                 *" << std::endl;
	ofs << "***************************************************************************************************" << std::endl;
}