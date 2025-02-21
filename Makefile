NAME = cub3D
NAME_Bonus = cub3D_bonus
all :
	make -C ./Mandatory
bonus :
	make -C ./Bonus

fclean :
	make fclean -C ./Mandatory
fclean_bonus :
	make fclean -C ./Bonus

clean :
	make clean -C ./Mandatory
clean_bonus :
	make clean -C ./Bonus

re :
	make re -C ./Mandatory
re_bonus :
	make re -C ./Bonus
mlx:
	make mlx -C ./Mandatory && make mlx -C ./Bonus
.PHONY: all bonus fclean fclean_bonus clean clean_bonus re re_bonus 