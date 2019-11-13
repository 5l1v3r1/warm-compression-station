function varargout = PropsSI(varargin)
   try
        [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(246,varargin{:});
   catch
        [varargout{1:max(1,nargout)}] = NaN;
   end
end
