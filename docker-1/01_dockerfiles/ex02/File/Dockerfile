FROM ruby:2.3.1
RUN apt-get update 
RUN apt-get install -y nodejs
RUN gem install rails -v 4.2.7 
RUN mkdir -p /opt/app

ONBUILD WORKDIR /opt/app
ONBUILD ADD app/ /opt/app
ONBUILD EXPOSE 3000
ONBUILD RUN bundle install 
ONBUILD RUN rake db:migrate 
ONBUILD RUN rake db:seed