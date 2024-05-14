module.exports = {
  root: true,
  plugins: ['prettier'],
  extends: '@react-native',
  rules: {
    'prettier/prettier': 'error',
    'react/react-in-jsx-scope': 'off',
  },
};
