## HelloWorld



## 日志



## JWT

 JSON Web Token

[https://github.com/auth0/java-jwt](https://github.com/auth0/java-jwt)

[https://github.com/jwtk/jjwt](https://github.com/jwtk/jjwt)

## 全局异常捕获

```java
@ControllerAdvice
public class GlobalExceptionHandler {

    @ExceptionHandler(UserException.class)
    @ResponseBody
    public BaseResult userExceptionHandler(HttpServletRequest req, UserException e){

        return ResultFactory.createFailure("");
    }

    @ExceptionHandler(Exception.class)
    @ResponseBody
    public BaseResult globalExceptionHandler(HttpServletRequest req, Exception e){

        return ResultFactory.createFailure("服务器内部错误");
    }

    @ExceptionHandler(RuntimeException.class)
    @ResponseBody
    public BaseResult runtimeExceptionHandler(HttpServletRequest req, RuntimeException e){

        return ResultFactory.createFailure(e.getMessage());
    }
}
```

## 拦截器

```java
@Configuration
public class WebSecurityConfig extends WebMvcConfigurationSupport {

    @Autowired
    NotLoginInterceptor notLoginInterceptor;

    @Override
    public void addInterceptors(InterceptorRegistry registry) {
        super.addInterceptors(registry);

        registry.addInterceptor(notLoginInterceptor)
                .addPathPatterns("/**")
                .excludePathPatterns("/user/register", "/user/login");
    }

    @Override
    protected void addResourceHandlers(ResourceHandlerRegistry registry) {

        super.addResourceHandlers(registry);
    }

}
```

```java
@Component
public class NotLoginInterceptor extends HandlerInterceptorAdapter {


    /*
     * 进入controller层之前拦截请求
     */
    @Override
    public boolean preHandle(HttpServletRequest request,
                             HttpServletResponse response,
                             Object handler) throws Exception {

        String token = request.getHeader("token");
        response.setContentType("application/json;charset=UTF-8");
        if (StringUtils.isEmpty(token)) {
            BaseResult result = ResultFactory.createFailure("用户未登录");
            ObjectMapper mapper = new ObjectMapper();
            mapper.writeValue(response.getOutputStream(), result);
            response.getOutputStream().close();
//            response.getWriter().write(mapper.);
//            response.getWriter().close();
            return false;
        }

        return super.preHandle(request, response, handler);
    }

    /*
     * 处理请求完成后视图渲染之前的处理操作
     */
    @Override
    public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler,
                           ModelAndView modelAndView) throws Exception {

        super.postHandle(request, response, handler, modelAndView);

    }

    /*
     * 视图渲染之后的操作
     */
    @Override
    public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler,
                                Exception ex) throws Exception {
        super.afterCompletion(request, response, handler, ex);

    }
}
```

## 过滤器



## Lombok

[https://projectlombok.org](https://projectlombok.org)

```xml
<dependency>
		<groupId>org.projectlombok</groupId>
		<artifactId>lombok</artifactId>
		<version>1.18.4</version>
		<scope>provided</scope>
</dependency>
```

The [Jetbrains IntelliJ IDEA](https://www.jetbrains.com/idea/) editor is compatible with lombok.

Add the [Lombok IntelliJ plugin](https://plugins.jetbrains.com/plugin/6317) to add lombok support for IntelliJ:

- Go to `File > Settings > Plugins`
- Click on `Browse repositories...`
- Search for `Lombok Plugin`
- Click on `Install plugin`
- Restart IntelliJ IDEA

## Swagger

[https://swagger.io/](https://swagger.io/)

