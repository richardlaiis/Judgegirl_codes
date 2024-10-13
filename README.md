# Judge Girl Codes
Solutions for problems in C programing lecture 2024. I hope I can get A+ on this course;D.
## My .vimrc configuration
```
set nocompatible              " be iMproved, required
filetype off                  " required

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'
Plugin 'scrooloose/nerdtree'
Plugin 'suan/vim-instant-markdown'
Plugin 'honza/vim-snippets'
Plugin 'arcticicestudio/nord-vim'

call vundle#end()            " required
filetype plugin indent on    " required

:set nu
:set rnu
:set cursorline
:set tabstop=4
:set shiftwidth=4
:set incsearch
:set termguicolors
:syntax on

:colorscheme nord
":hi LineNr cterm=bold ctermfg=DarkGrey ctermbg=NONE
":hi CursorLineNr cterm=bold ctermfg=DarkCyan ctermbg=NONE

:inoremap ( ()<Esc>i
:inoremap [ []<Esc>i
:inoremap [ []<Esc>i
:inoremap " ""<Esc>i
:inoremap ' ''<Esc>i
:inoremap {<CR> {<CR>}<Esc>ko
:inoremap {{ {}<Esc>i
:inoremap jk <Esc>
:inoremap <F5> <Esc><F5>

:nnoremap <C-b> :NERDTreeFocus<CR>
:nnoremap <C-n> :NERDTree<CR>
:nnoremap <C-t> :NERDTreeToggle<CR>
:nnoremap <C-f> :NERDTreeFind<CR>
:nnoremap <F5> :w<CR>:!clear;gcc %:r.c -DDEBUG -o %:r && echo "Compiled" && ./%:r<CR>
:nnoremap <F6> :w<CR>:!clear;python3 %<CR>
```
## Lecture Resources
https://github.com/pangfengliu/C202X
