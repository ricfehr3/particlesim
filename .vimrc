set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab

set colorcolumn=110
highlight ColorColumn ctermbg=darkgray

"augroup project
"    autocmd!
"    autocmd BufRead,BufNewFile *.h,*.c, *.cpp set filetype=c.doxygen
"augroup END

" let &path.="src/include,/usr/include/AL,"

nnoremap <F4> :make!<cr>
nnoremap <F5> :!./loveTest<cr>
