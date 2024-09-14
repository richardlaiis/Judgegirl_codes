# Judge Girl Codes
solutions for problems in C programing lecture 2024.
## My .vimrc
```
" test
set nocompatible              " be iMproved, required
filetype off                  " required

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'
Plugin 'scrooloose/nerdtree'
Plugin 'suan/vim-instant-markdown'

call vundle#end()            " required
filetype plugin indent on    " required

:set nu
:set cursorline
:set tabstop=4
:set shiftwidth=4
:set incsearch
:syntax on

:set bg=dark
:color evening
:hi LineNr cterm=bold ctermfg=DarkGrey ctermbg=NONE
:hi CursorLineNr cterm=bold ctermfg=DarkCyan ctermbg=NONE

:inoremap ( ()<Esc>i
:inoremap [ []<Esc>i
:inoremap [ []<Esc>i
:inoremap " ""<Esc>i
:inoremap ' ''<Esc>i
:inoremap {<CR> {<CR>}<Esc>ko
:inoremap {{ {}<Esc>i
:inoremap jk <Esc>:w<CR>
:inoremap <F5> <Esc><F5>
:inoremap qq <Esc>:wq<CR>

:nnoremap <C-b> :NERDTreeFocus<CR>
:nnoremap <C-n> :NERDTree<CR>
:nnoremap <C-t> :NERDTreeToggle<CR>
:nnoremap <C-f> :NERDTreeFind<CR>
:nnoremap <F5> :w<CR>:!gcc %:r.c -o %:r && echo "Compiled" && ./%:r<CR>
```
