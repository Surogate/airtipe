SRCS		=	Activity.dot		\
				Package.dot			\
				UseCases.dot

DOT			=	dot

doc			:	clean
				$(DOT) $(SRCS) -T png -O

clean		:
				rm -f *.png
