all :
	make -C ./Mandatory
bonus :
	make -C ./Bonus
fclean :
	make fclean -C ./Mandatory
fclean_bonus :
	make fclean -C ./Bonus
re :
	make re -C ./Mandatory
re_bonus :
	make re -C ./Bonus
	
.PHONY: all bonus