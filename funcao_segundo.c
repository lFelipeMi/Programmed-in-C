#include <stdio.h>

int main() {
    int a, b, c;
    float y, epsilon;

    scanf("%d %d %d %f %f", &a, &b, &c, &y, &epsilon);
    
    int delta = b * b - 4 * a * c;
    
    if (delta < 0) 
    {
        printf("Não há raízes reais.\n");
    } else if (delta == 0) 
    {
        float raiz_delta = -b / (2.0 * a);
        printf("Há uma raiz real: %f.\n", raiz_delta);
    } 
    else 
    {
        float raiz_delta = y;
        float delta_temp;
        
        do 
        {
            float temp = raiz_delta;
            delta_temp = delta;
            raiz_delta = 0.5 * (temp + delta_temp / temp);
            delta_temp = temp - raiz_delta;
            if (delta_temp < 0)
                delta_temp = -delta_temp;
        } 
        while (delta_temp >= epsilon);
        
        float raiz_delta1 = (-b + raiz_delta) / (2.0 * a);
        float raiz_delta2 = (-b - raiz_delta) / (2.0 * a);
        printf("Há duas raízes reais: %f e %f\n", raiz_delta1, raiz_delta2);
    }
    
    return 0;
}
