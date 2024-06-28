import styled, {css} from 'styled-components/native';

export const MainContainer = styled.View`
  ${({theme: {theme}}) => css`
    flex: 1;
    background-color: ${theme.colors.background};
  `}
`;
