-- below is the lua version of above
vim.api.nvim_set_keymap('n', ',.', ':term make %:r && echo "" && ./%:r<CR>', { noremap = true })
vim.api.nvim_set_keymap('n', ',m', ':term make %:r && echo "" && gdb ./%:r<CR>', { noremap = true })
